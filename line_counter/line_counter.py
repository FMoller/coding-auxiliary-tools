"""Line Counter

Read a script and extract useful info  
"""

__author__ = "Frederico Moeller"
__copyright__ = "Copyright 2021, Frederico Moeller"
__credits__ = ["Frederico Moeller"]
__license__ = "MIT"
__version__ = "0.1"
__maintainer__ = "Frederico Moeller"
__email__ = "fredericomollerped@gmail.com"
__status__ = "Prototype"

import pandas as pd

file_name = "python_test.py"
file_path = "TestCodes/"
lang_data = pd.read_csv("plang.csv")
lang_data = lang_data.set_index('ext')

def get_ext(f_name):
    """Get the file extension"""
    
    for i in range(len(f_name)-1,-1,-1):
        if f_name[i]=='.':
            return f_name[i:]
    return None

## I doubt I need it:
##def read_ln(code,end,st=0):
##    """read the code until an ionstruction stop"""
##
##    att = dict()
##    for i in end:
##        if i[0] not in att.keys():
##            att[i[0]]=[]
##        att[i[0]].append(i)
##    
##    for i in range(st,len(code)):
##        if code[i] in att.keys():
##            for j in att[code[i]]:
##                
##            return(code[st:i+1],i+1)
##    return("",len(code))
##        
##
##def is_mlcmto(line,mlcmto):
##    """Test if the line is an start of a
##    multiple line comment, or docstring
##    """
##    return line[:len(mlcmto)]== mlcmto
##
##def is_mlcmtc(line,mlcmtc):
##    """Test if the line is an end of a
##    multiple line comment, or docstring
##    """
##    return line[-len(mlcmto):]== mlcmtc

def get_mlcmts(l_data):
    """ Get the multiple lines comment, or
    docstring delimiters"""

    delim = [l_data["mlcmto"],l_data["mlcmtc"]]
    for i in range(2):
        if delim[i] == '3dq':
            delim[i] = '"""'
    return delim
    


def get_info(f_path,f_name):
    """Extract the info about the file"""

    d_string = False
    d_str_c = 0
    ext = get_ext(f_name)
    try:
        l_data = lang_data.loc[ext]
        print("File:",f_name)
        print("Language:",l_data["name"])
        end = ["\n",'"""']
    except:
        raise ValueError("Extension not found in plang.csv")
    f = open(f_path+f_name,"r")
    while True:
        line = f.readline()
        print(list(line))
        print("")
        if len(line)==0:
            break
##        else:
##            if d_string:
##                d_str_c+=1
                
                

        
    
    

get_info(file_path,file_name)
