# executar na raiz do projeto
import csv
from string import Template

# settings
path_output_file = './problems.md'
key_root = (0, 'root')
emojis = {
   'easy': '📗',
   'medium': '📙',
   'hard': '📕',
   'undefined': '📓'
}

# graph representation (pair: set())
adjList = { key_root: set() }
# list of exercices of each leaf vertex (pair: set())
leaf = {}

# build adjacency list of graph and define leaf
def build(dataset):
   for data in dataset:
      themes = data['themes'].split(' > ')

      for i in range(0, len(themes)):
         key = key_root if i == 0 else (i, themes[i-1])
         adjList[key].add((i+1, themes[i]))
         adjList.setdefault((i+1, themes[i]), set())

      key_leaf = (len(themes), themes[-1])
      leaf.setdefault(key_leaf, set())
      ex_desc = Template('$emoji [$judge/$problem](https://github.com/brnpapa/competitive-programming/blob/master/$judge/$problem$ext): $name')
      leaf[key_leaf].add(ex_desc.substitute(data, emoji=emojis[data['difficulty']]))

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

# append to path_output_file
def vertex_process(v):
   if (v == key_root):
      return
   level, theme = v
   with open(path_output_file, 'a') as file:
      if level == 1:
         file.write('# '+theme+'\n')
      else:
         file.write('\t'*(level-2)+'- **' + theme + ':**\n')

      if v in leaf:
         for ex_desc in leaf[v]:
            file.write('\t'*(level-1)+'- ' + ex_desc + '\n')       

# overwrite path_output_file
def write_header():
   with open(path_output_file, 'w') as file:
      for v in adjList[key_root]:
         theme = str(v[1])
         link = theme.replace(' ', '-')
         file.write(f'- **[{theme}](#{link})**\n')
      file.write('\n')


if __name__ == '__main__':
   build(csv.DictReader(open('problems.csv')))
   write_header()
   dfs(key_root, vertex_process)