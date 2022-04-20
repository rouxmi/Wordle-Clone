document.addEventListener("DOMContentLoaded", () => {
    //initialisation des variables
    if (mode_libre==1){
      var mode="libre"; 
    }
    else{
      var mode="jour";  
    }
    var lang="fr";
    var motsTentees=[[]];
    var index=0;
    var motADevine;
    var couleur;
    var existe;
    var rouge=[];
    var jaune=[];
    

    //création de la requête pour obtenir le mot de la partie
    var mot=fetch('/getmot?mode='+mode+'&lang='+lang+"&size="+size+"&niveau="+niveau) //envoie du mode, de la langue, la taille et le niveau du mot voulus
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
        if (motADevine!=''){  //vérication que la réponse n'est pas vide
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
  
    //dans motsTentés on stoques tous les mots essayés
    
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
       /* if(niveau ==1){
            if(index==1){
              lettre = motadev[1];
            }
            if(index==size){
              lettre = motadev[size];
            }
            motActuel.push(lettre);
            const placeCourante=document.getElementById(String(index));
            index=index+1;
            placeCourante.textContent=lettre;
          }
          if(niveau ==2){
            if(index ==1){
              lettre = motadev[1];
            }
            motActuel.push(lettre);
            const placeCourante=document.getElementById(String(index));
            index=index+1;
            placeCourante.textContent=lettre;
          }
          else{} */
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
        //sinon si le nombre d'essais possibles n'est pas atteint
        if(motsTentees.length<=nbrEssais){
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
          const coloration = async () => {

            const couleur = await appel; //attente de la réponse serveur

            //test si la requête n'a pas échouer
            if (couleur!=""){

              //test si le mot existe
              if (couleur[0]=="True"){

                //ajout du mot tentés dans la liste
                motsTentees.push([]);

                var numeroligne=motsTentees.length-2; /* je recupere le numero de la derniere ligne dans lequel l'utilisateur a écrit*/
                var tailleMot=motADevine.length;
                for (let i = 0; i<couleur[1].length; i++){ 
                  var numerodecase=numeroligne*tailleMot+i; /* je calcule la case à colorer*/
                  let square=document.getElementById(numerodecase); /*je recupere le div correspondant*/
                  var contenu = 'l'+square.innerHTML;
                  let key= document.getElementById(contenu.toUpperCase());
                  switch(couleur[1][i]){
                    case "1":
                      $(square).css('background-color','yellow');
                      if(!(rouge.includes(key))){
                        $(key).css('background-color','yellow');
                      }
                      jaune.push(key);
                      break;
                    case "2":
                      $(square).css('background-color','red');
                      $(key).css('background-color','red');
                      rouge.push(key);
                      break;
                    case "0":
                      $(square).css('background-color','grey');
                      if(!(rouge.includes(key))){
                        if(!(jaune.includes(key))){
                          $(key).css('background-color','grey');
                        }
                      }
                      break;
                    default:
                      break;
                  }
                }
                if(mot==motADevine){
                  window.alert("BRAVO");
                }
                else{
                  if(motsTentees.length>nbrEssais){
                    window.alert("tu as réalisé trop d'essais le mot était:  "+motADevine);
                  }
                }
              }

              //si le mot n'existe pas suppression
              else{
                var motActuel=getMotActuel(); //on récupère le mot
                motsTentees.splice(motsTentees.indexOf(motActuel,1))
                motsTentees.push([])
                //on boucle sur la longeur du mot
                for(i=0;i<size;i++){
                  //on récupère la case
                  var placeCourante=document.getElementById(String(index-1));
                  //on diminue l'index après la suppression
                  index=index-1; 
                  //on vide la case pour le visuel
                  placeCourante.textContent="";
                };
                //alerte que le mot n'existe pas
                alert("ton mot n'est pas dans le dictionnaire")
              }
            };
          };
          //appel de la requête sur le mot
          coloration();
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

  