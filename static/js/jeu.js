document.addEventListener("DOMContentLoaded", () => {

    let motADevine='LUCIE';
    
    //index correspond à la case qui va être rempli
    let index=0;

    //touches correspond à l'enssemble des boutons dans le clavier
    const touches = document.querySelectorAll(".keyboard-row button");
  
    //dans motsTentés on stoques tous les mots éssayés
    let motsTentees=[[]]

    /*getMotActuel
     * @return : un tableau de lettres correspondant au mot actuel en train d'être écrit dans la grille
     */
    function getMotActuel(){
      return motsTentees[motsTentees.length-1];
    }

    /*getMotActuel
     * @param : lettre, la lettre qui vient d'être soumise
     * @param : size la taille du mot à deviner
     * la fonction ajoute au tableau des mots la lettre soumise et réalise l'affichage dans la grille
     */
    function majTableau(lettre, size){
      const motActuel= getMotActuel();
      if(motActuel && motActuel.length<size){
        motActuel.push(lettre);
        const placeCourante=document.getElementById(String(index));
        index=index+1;
        placeCourante.textContent=lettre;
      }
    }

    /*gestionEntree
     * la fonction gère l'appuie sur la touche ENTREE
     */
    function gestionEntree(){
      const motActuel=getMotActuel();

      //si le joueur n'a pas rempli toutes les cases de la ligne on affiche un message d'erreur
      if(motActuel.length<size){
        window.alert("Ton mot est trop petit");
      }
      //si le mot de la ligne correspond au mot à deviner, le joueur à gagné
      else{mot=motActuel.join("");
      if(mot==motADevine){
        window.alert("BRAVO");
      }
      else{
        //sinon si le nombre d'essais possibles n'est pas atteint
        if(motsTentees.length<nbrEssais){
          motsTentees.push([]);
        }
        else{
          window.alert("tu as réalisé trop d'essais");
        }
      }
    }
    }

    /*gestionSupprime
     * la fonction gère l'appuie sur la touche DEL
     */
    function gestionSupprime(){
      const motActuel=getMotActuel();
      if(motActuel.length>0){
        motActuel.pop();
        const placeCourante=document.getElementById(String(index-1));
        index=index-1;
        placeCourante.textContent="";
      }
    }
    //cette partie correspond à l'écoute de l'entrée standard
    window.addEventListener("keydown", function (event) {
      if (event.defaultPrevented) {
        return; // Ne devrait rien faire si l'événement de la touche était déjà consommé.
      }
      switch (event.key) {
        case "Enter":
          gestionEntree();
          break;
        case "Backspace":
          gestionSupprime();
          break;
        case "a":
        case "b":
        case "c":
        case "d":
        case "e":
        case "f":
        case "g":
        case "h":
        case "i":
        case "j":
        case "k":
        case "l":
        case "m":
        case "n":
        case "o":
        case "p":
        case "q":
        case "r":
        case "s":
        case "t":
        case "u":
        case "v":
        case "w":
        case "x":
        case "y":
        case "z":
          majTableau(event.key.toUpperCase(),size);
          break;
        default:
          return; // Quitter lorsque cela ne gère pas l'événement touche.
      }
    
      // Annuler l'action par défaut pour éviter qu'elle ne soit traitée deux fois.
      event.preventDefault();
    }, true);
    
    for (let i = 0; i < touches.length; i++) {
        touches[i].onclick = ({ target }) => {
          const lettre = target.getAttribute("data-key");
          if (lettre === "entree") {
            gestionEntree();
            return;
          }
    
          if (lettre === "supprimer") {
            gestionSupprime();
            return;
          }
          majTableau(lettre,size);
    
        };
    };
    
  
  });
  