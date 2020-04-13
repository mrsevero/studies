import requests
from bs4 import BeautifulSoup

html = requests.get('https://qz.com/africa/latest/')
soup = BeautifulSoup(html.text, "html.parser")

for news in soup.find_all('div', class_="_435a3 context-list"):
  
  title = news.h3.text
  print('Title: '+title)

  link = news.find('a', class_='_5ff1a')['href']
  print('Link: '+'https://qz.com'+link+'\n')

