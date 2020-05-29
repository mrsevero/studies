from UrlExtrator import UrlExtrator

url = 'https://www.bytebank.com.br/cambio?moedaorigem=moedadestino&moedadestino=dolar'
##url = None

argumentos = UrlExtrator(url)

##print(argumento)

#print(UrlExtrator.UrlValidation(url))


moedaOrigem, moedaDestino = argumentos.ExtractArgs()

print(moedaOrigem)
print(moedaDestino)