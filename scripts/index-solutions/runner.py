import collections
import subprocess
from string import Template
from typing import Tuple, Dict, Set, List, cast

from data import config

Vertex = Tuple[int, str] # level, label

# graph representation, where Tuple[int, str] identify a unique vertex
root: Vertex = (0, 'root')
adj_list: Dict[Vertex, Set[Vertex]] = { root: set() }
leaf: Dict = {} # list of exercices of each leaf vertex

# build adj_list, leaf and define main_judges
def build(dataset):
   for data in dataset:
      if (data['difficulty'] not in config['emojis']['difficulty']):
         continue

      if (data['judge_id'] in config['main_judges']):
         config['main_judges'][data['judge_id']]['solved'] += 1

      # filter
      if (data['difficulty'] == 'none'):
         continue

      for i in range(0, len(data['theme'])):
         key = root if i == 0 else (i, data['theme'][i-1])
         adj_list[key].add((i+1, data['theme'][i]))
         adj_list.setdefault((i+1, data['theme'][i]), set())

      ex_desc = Template('$emoji [$judge_id/$problem_id](./$relative_path)$problem_desc $hint_desc')

      key_leaf = (len(data['theme']), data['theme'][-1])
      leaf.setdefault(key_leaf, set())

      leaf[key_leaf].add(ex_desc.substitute(
         data,
         problem_desc=('' if data['problem_desc'] == 'none' else f': `{data["problem_desc"]}`'),
         hint_desc=('' if data['hint_desc'] == 'none' else f' → {data["hint_desc"]}'),
         relative_path=f'{data["judge_id"]}/{data["problem_id"]}.{data["ext"]}',
         emoji=config['emojis']['difficulty'][data['difficulty']]
      ))

# traverse the graph executing fn(u) for each vertex
def dfs(u, fn):
   visiteds = {u}
   stack = [u]

   while len(stack):
      u = stack.pop()
      fn(u)

      for v in adj_list[u]:
         if not v in visiteds:
            visiteds.add(v)
            stack.append(v)

# append the handled u vertex to path
def append_to_file(u, path):
   if (u == root):
      return
   level, theme = u
   with open(path, 'a') as file:
      if level == 1:
         file.write('\n## '+theme+'\n')
      else:
         file.write('\t'*(level-2)+'- **' + theme + '**\n')

      if u in leaf:
         for ex_desc in leaf[u]:
            file.write('\t'*(level-1)+'- ' + ex_desc + '\n')

# overwrite path
def overwrite_file(path):
   with open(path, 'w') as file:
      file.writelines(config['static_output_lines'])

      shields_io = Template('<a href="$url"><img src="https://img.shields.io/static/v1?label=$label&message=$message&color=$color&style=flat-square"></a>\n')

      file.write('<p align="center">\n')
      for judge_id in config['main_judges'].keys():
         file.write(shields_io.substitute(url=config['main_judges'][judge_id]['profile_url'], label=judge_id, message=config['main_judges'][judge_id]['solved'], color='green'))
      file.write('</p>\n')

      file.write('<br/>\n\n')
      file.write('<h1 align="center">Solutions index</h1>\n\n')
      for u in adj_list[root]:
         link = '#' + str(u[1]).replace(' ', '-')
         file.write(f'· [{link}]({link}) ')
      file.write('·\n')

# return all metadata of all problems
def get_dataset(paths):
   dataset: List[Dict] = []

   for path in paths:
      with open(path, 'r') as problem_file:
         problem_file.readline()
         
         theme = problem_file.readline().strip().split(' > ')
         difficulty = problem_file.readline().strip().replace('difficulty: ', '', 1)
         date = problem_file.readline().strip().replace('date: ', '', 1)

         opt_any = problem_file.readline().strip()
         if (opt_any.startswith('problem: ')):
            problem_desc = opt_any.replace('problem: ', '', 1)
            opt_any = problem_file.readline().strip()
         else:
            problem_desc = 'none'

         if (opt_any.startswith('hint: ')):
            hint_desc = opt_any.replace('hint: ', '', 1)
         else:
            hint_desc = 'none'

         dataset.append({
            'judge_id': path.split('/')[1],
            'problem_id': path.split('/')[2].split('.')[0],
            'ext': path.split('/')[2].split('.')[1],
            'theme': theme,
            'difficulty': difficulty,
            'date': date,
            'problem_desc': problem_desc,
            'hint_desc': hint_desc
         })

   return dataset

# entry
if __name__ == '__main__':
   # get files tracked on git
   response = subprocess.run(['git', 'ls-files'], text=True, stdout=subprocess.PIPE)
   problems_paths = response.stdout.split('\n')
   problems_paths = [path for path in problems_paths if 'solutions/' in path and '.cpp' in path]

   build(get_dataset(problems_paths))

   output_path = cast(str, config['output_path'])
   overwrite_file(output_path)
   dfs(root, lambda u: append_to_file(u, output_path))
