import PyLabEHPY as PyLab
import sys

def challengeX(data):
    pass
    return

def challenge1(data):
    ''' Função para resolver o challenge 01 '''
    pass


apikey = ''
lab = PyLab.Lab(host='IP', port='8443', apikey=apikey)
questionnumber = int(sys.argv[1])

qdata = lab.GetQuestionData(questionnumber)
lab.SendAnswer(questionnumber, eval(f'Challenge{questionnumber}')(qdata)))
