cmake_minimum_required(VERSION 3.17)
project(untitled2 C)

set(CMAKE_C_STANDARD 99)
set(dirc "Prog_01Es/")
set(dircpp "Prog_02Es/")
add_executable(untitled2 main.c)
add_executable(main2 main2.c)
add_executable(main3 password.c)
add_executable(giochino giochino.c)
add_executable(main4 main3.c areacerchio.c)
add_executable(tabverit tabverit.c)
add_executable(ciclifor ciclifor.c)
add_executable(maxcol maxcol.c maxcolfunc.c)
add_executable(es147 es147.c libk.c)
add_executable(es1 es1.c)
add_executable(es2 es2.c)
add_executable(es3 es3.c)
add_executable(es4 es4.c)
add_executable(escorona escorona.c library.c)
add_executable(esassoluto esassoluto.c library.c)
add_executable(distanzaes distanzaes.c library.c)
add_executable(printes printeins.c library.c)
add_executable(sommarr sommarr.c library.c)
add_executable(merge merge.c mergelib.c)
add_executable(perfectNum perfectNum.c)
add_executable(kesimo kesimomax.c kesimolib.c)
add_executable(sorts sorts.c sortslib.c)
add_executable(biggestword biggestword.c)
add_executable(wordandlen wordandlen.c)
add_executable(eserciziprova eserciziprova.c)
add_executable(eserciziprova2 eserciziprova2.c)
add_executable(eserciziprova3 eserciziprova3.c)
add_executable(eserciziprova4 eserciziprova4.c)
add_executable(esprovainter esprovainter.c)
add_executable(randomstuff randomstuff.c)
add_executable(CoppieDiCarte "Relazione_Palumbo_Stefano/C/Traccia 1 - Gioco delle coppie di carte/CoppieDiCarte.c" "Relazione_Palumbo_Stefano/C/Traccia 1 - Gioco delle coppie di carte/CarteLib.c")
add_executable(riciclatore "Relazione_Palumbo_Stefano/C/Traccia 2 - Riciclatore Automatico/Riciclatore.c" "Relazione_Palumbo_Stefano/C/Traccia 2 - Riciclatore Automatico/RiciclatoreLib.c")