import requests
import json
import os
import hashlib

urlpostagem = 'https://api.codenation.dev/v1/challenge/dev-ps/submit-solution?token=adfa50a190f61a6965fd4fd077cb7a74435d1993'
urlget = 'https://api.codenation.dev/v1/challenge/dev-ps/generate-data?token=adfa50a190f61a6965fd4fd077cb7a74435d1993'
#abre arquivo Json e salva na variavel data
filename = 'answer.json'
arq = open (filename, "r") 
data = json.loads(arq.read())
#parametro para sha1 
encoding = arq.encoding



#post de arquivo multipart
def envioarquivo(filename, url):
  up = {'answer':(filename, open(filename, 'rb'), "multipart/form-data")}
  request = requests.post(url, files=up)
  print(request.text)

def getarquivo(url):
  r = requests.get(url)
  print(r.json())
  return r

def encriptar(texto,chave):
  resposta = ""

  texto2 = texto.lower()

  for i in range (len(texto)):
    temp = texto2[i]

    if (texto2[i].isdigit() or validate(texto2[i])):
      resposta += texto2[i]
      
    else:
      resposta += chr((ord(texto2[i]) + chave - 97) % 26 + 97)
    
  return resposta
  
#valida caracteres especiais
def validate(caracter):
  if ord(caracter) < 97 or ord(caracter) > 122:
    return True
  else:
    return False 

def decriptar(texto,chave):
  resposta = ""

  texto2 = texto.lower()

  for i in range (len(texto)):
    
    if (texto2[i].isdigit() or validate(texto2[i])):
      resposta += texto2[i]
      
    else:
      resposta += chr((ord(texto2[i]) - chave - 97) % 26 + 97)  #segundo tabela asc utiliza mod 26 para manter no alfabeto
    
  return resposta
  
#salva arquivo json
def savejson(filename):
  with open(filename, 'w') as f:
    json.dump(data, f, indent=4)
    print("arquivo salvo com sucesso")

#seleciona as informações recebidas do Json
texto = str(data["cifrado"])
chave = int(data["numero_casas"])

#aplica decriptação e escreve no data
textodecriptado = decriptar(texto,chave)
data["decifrado"] = textodecriptado

#aplicando sha1 no data decifrado e escreve no data
resumo = hashlib.sha1(data['decifrado'].encode(encoding)).hexdigest()
data['resumo_criptografico'] = resumo

#abrindo o arquivo para salvar alterações
savejson(filename)

#post de arquivo json
envioarquivo(filename, urlpostagem)