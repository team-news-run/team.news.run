#-*- coding : utf-8 -*-

from bs4 import BeautifulSoup
import urllib.request
import re



#OUTPUT_URL_FILE_NAME = 'headline.txt'
#OUTPUT_FILE_NAME = 'output.txt'

URL = 'http://news.naver.com/main/tv/list.nhn?mode=LSD&mid=tvh&sid1=290'

def get_url(URL):
	source_code_from_URL = urllib.request.urlopen(URL)
	soup = BeautifulSoup(source_code_from_URL, 'lxml',from_encoding='utf-8')
	text = set()
	for item in soup.find('ul',class_='type06').find_all('a'):
		text.add( str(item.get('href')))
	return text

def get_text(UURL):
	text =set()
	for ul in UURL: 
		source_code_from_URL = urllib.request.urlopen(ul)
		soup = BeautifulSoup(source_code_from_URL, 'lxml', from_encoding='utf-8')
		for item in soup.find_all('div', id='articleBodyContents'):
			text.add( str(item.find_all(text=True)))
	return text

def clean_text(text):
	cleaned_text = re.sub('[a-zA-Z]','',text)
	cleaned_text = re.sub('[\{\}\[\]\/?.,;:|\)*~`!^\-_+<>@\#$%&\\\=\(\'\"]','',cleaned_text)
	return cleaned_text



def main():
#	open_output_url_file = open(OUTPUT_URL_FILE_NAME,'w')
#	open_output_file = open(OUTPUT_FILE_NAME,'w')
	
#	crawURL = open(OUTPUT_URL_FILE_NAME,'r')
	
	result_text = get_text(get_url(URL))
	
	OUTPUT_BASE = 'output'
	a=0
	for re in result_text:
		open_output_file = open(OUTPUT_BASE + str(a)+str('.txt'),'w')
		open_output_file.write(clean_text(re))
		open_output_file.close()
		a=a+1

if __name__ == '__main__':
	main()
