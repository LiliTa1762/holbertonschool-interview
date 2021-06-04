#!/usr/bin/python3

import sys
import signal

statusList = [200, 301, 400, 401, 403, 404, 405, 500]
fileTotal = 0
statusCinco = 0
statusDos = 0
statusCuatro = 0
statusSeis = 0
statusOcho = 0
statusSiete = 0
statusTres = 0
statusUno = 0
count = 1


try:
    for line in sys.stdin:
        
        count += 1
        content = line.split()
        if len(content) == 9:
            status, filesize = int(content[7]), int(content[8])
            fileTotal += filesize	
            if status in statusList:
                if status == 200:
                    statusUno = statusUno + 1
                elif status == 301:
                    statusDos = statusDos + 1
                elif status == 400:
                    statusTres = statusTres + 1
                elif status == 401:
                    statusCuatro = statusCuatro + 1
                elif status == 403:
                    statusCinco = statusCinco + 1
                elif status == 404:
                    statusSeis = statusSeis + 1
                elif status == 405:
                    statusSiete = statusSeis + 1
                elif status == 500:
                    statusOcho = statusOcho + 1
                if count == 10:
                    print("File size:{:d}".format(fileTotal))
                    if statusUno != 0:
                        print("200:{:d}".format(statusUno))
                    else:
                        pass
                    if statusDos != 0 :
                        print("301:{:d}".format(statusDos))
                    else:
                        pass
                    if statusTres != 0 :
                        print("400:{:d}".format(statusTres))
                    else:
                        pass
                    if statusCuatro != 0 :
                        print("401:{:d}".format(statusCuatro))
                    else:
                        pass
                    if statusCinco != 0 :
                        print("403:{:d}".format(statusCinco))
                    else:
                        pass
                    if statusSeis != 0 :
                        print("404:{:d}".format(statusSeis))
                    else:
                        pass
                    if statusSiete != 0 :
                        print("405:{:d}".format(statusSiete))
                    else:
                        pass
                    if statusOcho != 0 :
                        print("500:{:d}".format(statusOcho))
                    else:
                        pass
                elif count > 10:
                    count = 0
                else:
                    pass

except:
    pass
finally:
        print("File size:{:d}".format(fileTotal))
        if statusUno != 0:
            print("200:{:d}".format(statusUno))
        else:
            pass
        if statusDos != 0 :
            print("301:{:d}".format(statusDos))
        else:
            pass
        if statusTres != 0 :
            print("400:{:d}".format(statusTres))
        else:
            pass
        if statusCuatro != 0 :
            print("401:{:d}".format(statusCuatro))
        else:
            pass
        if statusCinco != 0 :
            print("403:{:d}".format(statusCinco))
        else:
            pass
        if statusSeis != 0 :
            print("404:{:d}".format(statusSeis))
        else:
            pass
        if statusSiete != 0 :
            print("405:{:d}".format(statusSiete))
        else:
            pass
        if statusOcho != 0 :
            print("500:{:d}".format(statusOcho))
        else:
            pass

