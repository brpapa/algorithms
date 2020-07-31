import csv
import collections
import subprocess
from string import Template
from typing import Tuple, Dict, Set, cast

from settings import config

Vertex = Tuple[int, str] # level, label

# graph representation, where Tuple[int, str] identify a unique vertex
root: Vertex = (0, 'root')
adjList: Dict[Vertex, Set[Vertex]] = { root: set() }
leaf: Dict = {} # list of exercices of each leaf vertex

# build adjList, leaf and define main_judges
def build(dataset):
   for data in dataset:
      if (data['difficulty'] not in config['emojis']['difficulty']):
         continue

      if (data['folder'] in config['main_judges']):
         config['main_judges'][data['folder']]['solved'] += 1

      theme = data['theme'].split(' > ')

      # filter
      if (data['difficulty'] == 'none'):
         continue

      for i in range(0, len(theme)):
         key = root if i == 0 else (i, theme[i-1])
         adjList[key].add((i+1, theme[i]))
         adjList.setdefault((i+1, theme[i]), set())

      ex_desc = Template('$emoji [$folder/$file]($base_url/$relative_path)$problem_desc $hint_desc')

      key_leaf = (len(theme), theme[-1])
      leaf.setdefault(key_leaf, set())

      leaf[key_leaf].add(ex_desc.substitute(
         data,
         problem_desc=('' if data['problem'] == 'none' else f': `{data["problem"]}`'),
         hint_desc=('' if data['hint'] == 'none' else f' → {data["hint"]}'),
         base_url=config['base_url']['remote'],
         relative_path=f'{data["folder"]}/{data["file"]}.{data["ext"]}',
         emoji=config['emojis']['difficulty'][data['difficulty']]
      ))

# traverse the graph executing fn(u) for each vertex
def dfs(u, fn):
   visiteds = {u}
   stack = [u]

   while len(stack):
      u = stack.pop()
      fn(u)

      for v in adjList[u]:
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
      for judge in config['main_judges'].keys():
         file.write(shields_io.substitute(url=config['main_judges'][judge]['profile_url'], label=judge, message=config['main_judges'][judge]['solved'], color='green'))
      file.write('</p>\n')

      file.write('<br/>\n\n')
      file.write('<h1 align="center">Solutions categorized into themes</h1>\n\n')
      for u in adjList[root]:
         link = '#' + str(u[1]).replace(' ', '-')
         file.write(f'· [{link}]({link}) ')
      file.write('·\n')

if __name__ == '__main__':
   input_path = cast(str, config['input_path'])
   output_path = cast(str, config['output_path'])

   # TODO: depreceate problems.csv
   # response = subprocess.run(['git', 'ls-files'], text=True, stdout=subprocess.PIPE)
   # response.stdout

   build(csv.DictReader(open(input_path)))

   overwrite_file(output_path)
   dfs(root, lambda u: append_to_file(u, output_path))
