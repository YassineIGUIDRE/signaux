#!/bin/bash

  gnome-terminal -- nano
  pid=`pidof nano`

while true;do

  echo "------- Les principaux signaux ------- "
  echo "1 - SIGKILL Pour tuer le processus"
  echo "2 - SIGSTOP Pour suspendre le processus"
  echo "3 - SIGCONT Pour continuer le processus suspendu"
  echo "4 - SIGALRM Pour tuer le processus aprés une durée "
  echo "5 - Quitter"
  read -p "Veuillez choisissez un signal : " n

  case "$n" in
   "1")   kill -SIGKILL $pid
          echo "Le signal a été terminé"
          exit 0 ;; 
   "2")   kill -SIGSTOP $pid
          echo "Le signal a été suspendu";;
   "3")   kill -SIGCONT $pid
          echo "Le signal a continuer son exécution";;
   "4")   
          read -p "Entrez un nombre de secondes : " sec
          sleep $sec 
          kill -SIGALRM $pid
          echo "Le signal a été terminé";;
   "5")   exit 0 ;;
   *)
     echo "Veuillez entre une valeur correcte"
   ;;
  esac
done
