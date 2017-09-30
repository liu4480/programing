import requests
from bs4 import BeautifulSoup
import csv

URL="http://www.values.com/inspirational-quotes"

r=requests.get(URL)

soup = BeautifulSoup(r.content, 'html5lib')

quotes = []

table = soup.find('div', attrs={'class':'quote'})

for row in table.findAll('div', attrs={'class':'quote'}):
	quote = {}
	quote['theme'] = row.h5.text
	quote['url'] = row.a['href']
	quote['img'] = row.img['src']
	quote['lines'] = row.h6.text
	quote['author'] = row.p.text
	quotes.append(quote)

filename = "inspirational-quotes.csv"
with open(filename, 'wb') as f:
	w = csv.DictWriter(f, ['theme', 'url', 'img', 'lines', 'author'])
	w.writeheader()
	for quote in quotes:
		w.writerow(quote)
