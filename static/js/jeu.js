document.addEventListener("DOMContentLoaded", () => {

    //initialisation des variables
    var mode="libre"; 
    var lang="fr";
    var motsTentees=[[]];
    var index=0;
    var motADevine;
    var couleur;
    var existe;

    //création de la requête pour obtenir le mot de la partie
    var mot=fetch('/getmot?mode='+mode+'&lang='+lang+"&size="+size) //envoie du mode, de la langue et la taille du mot voulus
      .then(function (response) {
          //convertion de la réponse en json
          return response.json(); 
      }).then(function (text) {
          //récupération de la valeur mot dans la réponse
          motchoisis=text.mot;
          return motchoisis;
      });
    const getmot = async () => { //création de la fonction asyncrone
        const motADevine = await mot; //attente de la réponse du serveur 
        if (motADevine!=''){  //vérication que la réponse n'est pas vite
          //lancement de la partie
          start(motADevine) 
          console.log(motADevine)
        }
        };
    //lancement de la fonction asyncrone
    getmot();

    //fonction de lancement de la partie
    function start(motadev){
    
    //index correspond à la case qui va être rempli
    motADevine=motadev
    //touches correspond à l'enssemble des boutons dans le clavier
    var touches = document.querySelectorAll(".keyboard-row button");
  
    //dans motsTentés on stoques tous les mots éssayés
    
    //gestion du clavier virtuel
    for (let i = 0; i < touches.length; i++) {
      touches[i].onclick = ({ target }) => {
        var lettre = target.getAttribute("data-key");
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

    }

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

    function changeColor()
      {
        windoww.alert("je suis rentree dans la fonction");
        var indication=couleur[1];
        var numeroligne=motsTentees.length-1
        var tailleMot=motADevine.length-1
        for (let i=0; i<indication.length; i++){
          let numerodecase=numeroligne*tailleMot+i;
          let div=document.getElementById(numerodecase);
          switch(indication[i]){
            case 1:
              div.style.backgroundColor="yellow"
            break;
            case 2:
              div.css('background-color','red');
            break;
          };
        };

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
        // si le joueur est arrivé au nombre d'essais maximal et que son mot est faux
        if(motsTentees.length==nbrEssais){
          window.alert("tu as réalisé trop d'essais le mot était:  "+motADevine);
        }
        else{
        //sinon si le nombre d'essais possibles n'est pas atteint
        if(motsTentees.length<nbrEssais){
          //ajout du mot tentés dans la liste
          motsTentees.push([]);
          //création du requête pour vérifier si le mot existe et si oui donnée son vecteur couleur
          var appel=fetch('/checkmot?lang='+lang+"&essais="+mot)//passage du mot et de sa langue au serveur
          .then(function (response) {
              //convertion de la réponse en json
              return response.json();
          }).then(function (text) {
              //extraction de la valeur existe(booléen) et du vecteur couleur si oui
              existe=text.existe;
              couleur=text.couleur;
              return [existe,couleur];
          });
          const jeteste = async () => {
            const couleur = await appel;
            if (couleur!=""){
              if (couleur[0]=="True"){
                var indication=couleur[1];
                var divs=document.getElementsByClassName('square animate__animated');
                for (let i=0; i<indication.length; i++){
                  var div=divs[i]
                  switch(indication[i]){
                    case 1:
                      div.style.backgrounColor="yellow"; 
                    break;
                    case 2:
                      div.css({'background-color':'red'});
                    break;
                  }
                }
              };
            };
          };
          jeteste();

          //appel de la requête "appel" de manière asyncrone
          const coloration = async () => {

            const couleur = await appel; //attente de la réponse serveur

            //test si la requête n'a pas échouer
            if (couleur!=""){

              //test si le mot existe
              if (couleur[0]=="True"){
                alert(couleur[1])//renvoie du vecteur couleur (rajouter la coloration ici)
              }

              //si le mot existe pas suppression
              else{
                var motActuel=motsTentees[motsTentees.length-1]; //on récupère le mot

                //on boucle sur la longeur du mot
                for(i=0;i<size;i++){
                  //on supprime la dernière lettre
                  motActuel.pop();
                  //on récupère la case
                  var placeCourante=document.getElementById(String(index-1));
                  //on diminue l'index après la suppression
                  index=index-1; 
                  //on vide la case pour le visuel
                  placeCourante.textContent="";
                };
                //alerte que le mot n'existe pas
                alert('ton mot n\'est pas dans le dictionnaire')
              }
            };
          };
          //appel de la requête sur le mot
          coloration();
        }
        }
      }
    }
    }

    /*gestionSupprime
     * la fonction gère l'appuie sur la touche DEL
     */
    function gestionSupprime(){
      var motActuel=getMotActuel();
      if(motActuel.length>0){
        motActuel.pop();
        var placeCourante=document.getElementById(String(index-1));
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
    
    
    
  
  });

  