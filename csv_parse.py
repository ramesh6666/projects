import os
import re
import sys
import urllib.request
import shutil
import csv
import pandas as pd
import matplotlib.pyplot as plt

def main():
  f = open("/Users/rameshiyerbalan/Documents/electronic-card-transactions-november-2020-csv-tables.csv", "r")
  csv_reader = csv.reader(f, delimiter=',')
  for row in csv_reader:
      print(len(row))
      break
  df = pd.read_csv("/Users/rameshiyerbalan/Documents/electronic-card-transactions-november-2020-csv-tables.csv", nrows = 2)
  for dtype in df.dtypes.iteritems():
    print(dtype)

  print(df)
  df = pd.read_csv("/Users/rameshiyerbalan/Documents/electronic-card-transactions-november-2020-csv-tables.csv", parse_dates=['Period'])
  print(df[0:5])
  total_rows = df.count
  print(total_rows)
  print('Mean = ', df["Data_value"].mean())
  print(df['Period'])
  print(df['Data_value'])
  df.plot(x="Period", y="Data_value")
  plt.show()

if __name__ == '__main__':
  main()
