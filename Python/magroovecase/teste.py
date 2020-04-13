import requests
from bs4 import BeautifulSoup


r = requests.get('https://qz.com/africa/latest/')

soup = BeautifulSoup(r.text, "html.parser")

h3 = soup.find_all('a').get('href')

print(h3)