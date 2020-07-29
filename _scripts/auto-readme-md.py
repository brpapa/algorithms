#! /usr/local/bin/python

import csv
import collections
from string import Template

# settings
input_path = './_scripts/problems.csv'
output_path = './README.md'
emojis = {
   'difficulty': {
      # 'easy': '🟢',
      # 'medium': '🟡',
      # 'hard': '🔴',
      # 'none': '⚪️',
      # 'easy': '🟩',
      # 'medium': '🟨',
      # 'hard': '🟥',
      # 'none': '⬜️',
      # 'easy': '📗',
      # 'medium': '📙',
      # 'hard': '📕',
      # 'none': '📓',
      'easy': '🥦',
      'medium': '🧀',
      'hard': '🌶',
      'none': '🥚',
      # 'easy': '🙂',
      # 'medium': '😳',
      # 'hard': '🥵',
      # 'none': '😶'
   }
}
base_url = {
   'local': 'file:///Users/papa/Google%20Drive/dev/competitive-programming',
   'remote': 'https://github.com/brnpapa/competitive-programming/blob/master'
}
static_output_lines = [
   'Access my public [**notebook**](https://www.notion.so/brnpapa/icpc-notebook-0355e05508e9470fb065801e277f0c6c), a Notion workspace where I do my notes while studying and coding general-purpose algorithms. And feel free to follow my progress on my main online judge profiles:\n\n',
   '<!-- The book I recommend for studying is "Competitive Programming 3: The new lower bound of programming contests" by Steven Halim. --> \n\n'
]
main_judges = {
   'uva': {
      'solved': 0,
      'profile_url': 'https://uhunt.onlinejudge.org/id/1094350'
   },
   'codeforces': {
      'solved': 0,
      'profile_url': 'https://codeforces.com/profile/brnpapa'
   },
   'uri': {
      'solved': 0,
      'profile_url': 'https://www.urionlinejudge.com.br/judge/pt/users/statistics/310281'
   },
   'spoj': {
      'solved': 0,
      'profile_url': 'https://www.spoj.com/users/brnpapa'
   }
}

# graph representation
key_root = (0, 'root')
adjList = { key_root: set() }
leaf = {} # list of exercices of each leaf vertex

# build adjacency list of graph, define leaf and main_judges
def build(dataset):
   for data in dataset:
      if (data['difficulty'] not in emojis['difficulty']):
         continue

      if (data['folder'] in main_judges):
         main_judges[data['folder']]['solved'] += 1

      theme = data['theme'].split(' > ')

      # filter
      if (data['difficulty'] == 'none'):
         continue

      for i in range(0, len(theme)):
         key = key_root if i == 0 else (i, theme[i-1])
         adjList[key].add((i+1, theme[i]))
         adjList.setdefault((i+1, theme[i]), set())

      ex_desc = Template('$emoji [$folder/$file]($base_url/$relative_path)$problem_desc $hint_desc')

      key_leaf = (len(theme), theme[-1])
      leaf.setdefault(key_leaf, set())

      leaf[key_leaf].add(ex_desc.substitute(
         data,
         problem_desc=('' if data['problem'] == 'none' else f': `{data["problem"]}`'),
         hint_desc=('' if data['hint'] == 'none' else f' → {data["hint"]}'),
         base_url=base_url['remote'],
         relative_path=f'{data["folder"]}/{data["file"]}.{data["ext"]}',
         emoji=emojis['difficulty'][data['difficulty']]
      ))

# graph traversal, executing process function for each vertex
def dfs(v, process):
   visiteds = {v}
   stack = [v]

   while len(stack):
      v = stack.pop()
      process(v)

      for u in adjList[v]:
         if not u in visiteds:
            visiteds.add(u)
            stack.append(u)

# append to output_path
def vertex_process(v):
   if (v == key_root):
      return
   level, theme = v
   with open(output_path, 'a') as file:
      if level == 1:
         file.write('\n## '+theme+'\n')
      else:
         file.write('\t'*(level-2)+'- **' + theme + '**\n')

      if v in leaf:
         for ex_desc in leaf[v]:
            file.write('\t'*(level-1)+'- ' + ex_desc + '\n')

# overwrite output_path
def start_writing():
   with open(output_path, 'w') as file:
      file.writelines(static_output_lines)

      shields_io = Template('<a href="$url"><img src="https://img.shields.io/static/v1?label=$label&message=$message&color=$color&style=flat-square"></a>\n')

      file.write('<p align="center">\n')
      for judge in main_judges.keys():
         file.write(shields_io.substitute(url=main_judges[judge]['profile_url'], label=judge, message=main_judges[judge]['solved'], color='green'))
      file.write('</p>\n')

      file.write('<br/>\n\n')
      file.write('<h1 align="center">Solutions categorized into themes</h1>\n\n')
      for u in adjList[key_root]:
         link = '#' + str(u[1]).replace(' ', '-')
         file.write(f'· [{link}]({link}) ')
      file.write('·\n')


if __name__ == '__main__':
   build(csv.DictReader(open(input_path)))
   start_writing()
   dfs(key_root, vertex_process)
