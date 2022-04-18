document.addEventListener("DOMContentLoaded", () => {

    var mode="libre";
    var lang="fr";
    var motsTentees=[[]];
    var index=0;
    var motADevine;
    var couleur;
    var existe;
    var mot=fetch('/getmot?mode='+mode+'&lang='+lang+"&size="+size)
      .then(function (response) {
          return response.json();
      }).then(function (text) {
          motchoisis=text.mot;
          return motchoisis;
      });
    const getmot = async () => {
        const motADevine = await mot;
        if (motADevine!=''){
          start(motADevine)
          console.log(motADevine)
        }
        };
    getmot();

    function start(motadev){
    
    //index correspond à la case qui va être rempli
    motADevine=motadev
    //touches correspond à l'enssemble des boutons dans le clavier
    var touches = document.querySelectorAll(".keyboard-row button");
  
    //dans motsTentés on stoques tous les mots éssayés
    

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
        if(motsTentees.length==nbrEssais){
          window.alert("tu as réalisé trop d'essais le mot était:  "+motADevine);
        }
        else{
        //sinon si le nombre d'essais possibles n'est pas atteint
        if(motsTentees.length<nbrEssais){
          motsTentees.push([]);
          var appel=fetch('/checkmot?lang='+lang+"&essais="+mot)
          .then(function (response) {
              return response.json();
          }).then(function (text) {
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
          const coloration = async () => {
            const couleur = await appel;
            if (couleur!=""){
              if (couleur[0]=="True"){
                alert(couleur[1])
              }
              else{
                var motActuel=motsTentees[motsTentees.length-1];
                for(i=0;i<size;i++){
                  motActuel.pop();
                  var placeCourante=document.getElementById(String(index-1));
                  index=index-1;
                  placeCourante.textContent="";
                };
                alert('ton mot n\'est pas dans le dictionnaire')
              }
            };
          };
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

  