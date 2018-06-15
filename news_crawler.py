#-*- coding: utf-8 -*-

from bs4 import BeautifulSoup
import urllib.request
import sys
import re
 
# 출력 파일 명
OUTPUT_FILE_BASE = 'news_'


# 긁어 올 URL
## so : society
## ec : economic
## po : politics
## fo : foreign
## di : digital

#URL_so = 'http://media.daum.net/society/'
#URL_ec = 'http://media.daum.net/economic/'
#URL_po = 'http://media.daum.net/politics/'
#URL_fo = 'http://media.daum.net/foreign/'
#URL_di = 'http://media.daum.net/digital/'

## get the URL set
def get_url(URL):
	source_code_from_URL = urllib.request.urlopen(URL)
	soup = BeautifulSoup(source_code_from_URL, 'lxml', from_encoding='utf-8')
	text = set()
	for title in soup.find_all('strong',class_='tit_thumb',limit=5):
		for item in title.find_all('a'):
			text.add(str(item.get('href')))
#	for a in text:
#		print(a)
	return text
 
## get the bot's text
def get_text(URL) :
	text = set()
	for turl in URL:
		source_code_from_URL = urllib.request.urlopen(turl)
		soup = BeautifulSoup(source_code_from_URL,'lxml',from_encoding='utf-8')
		for item in soup.find_all('div',class_='btn_util util_summary'):
			text.add( str(item.find_all(text=True)))
	return text
	

## clean text func
def clean_text(text):
	cleaned_text = re.sub('[a-zA-Z]','',text)
	cleaned_text = re.sub('[\{\}\[\]\/?.,;:|\)*~`!^\-_+<>@\#$%&\\\=\(\'\"]','',cleaned_text)
	return cleaned_text


## text preClear func 
def preclean_text(text):
	clear = set()
	temp = ''
	for i in text:
		start = i.find('약\'')
		end = i.rfind('기사')
		temp = i[start+21:end]
		clear.add(temp)
	return clear


# 메인 함수
def main():
	a=0
	## argument is URL for Crawler
#	URL = sys.argv[1]


	result_text = preclean_text(get_text(get_url(URL_so)))
	
	for re in result_text:
		open_output_file = open(OUTPUT_FILE_BASE+str(a)+str('.txt'),'w')
		open_output_file.write(clean_text(re))
		open_output_file.close()
		a=a+1

    
if __name__ == '__main__':
    main()


