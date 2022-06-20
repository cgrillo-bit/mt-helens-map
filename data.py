import pandas as panda 

data = panda.read_csv('pre.data', sep='\t', encoding='utf8')
print(data)