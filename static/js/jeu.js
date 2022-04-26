document.addEventListener("DOMContentLoaded", () => {
    //initialisation des variables
    if (mode_libre==1){
      var mode="libre"; 
    }
    else{
      var mode="jour"; 
    };
    if (lang==1){
      var langue='fr';
    }
    else{
      var langue='en';
    };
    var motsTentees=[[]];
    var index=0;
    var motADevine;
    var couleur;
    var existe;
    var rouge=[];
    var jaune=[];
    var langue;
    
    

    //création de la requête pour obtenir le mot de la partie
    var mot=fetch('/getmot?mode='+mode+'&lang='+langue+"&size="+size+"&niveau="+niveau) //envoie du mode, de la langue, la taille et le niveau du mot voulus
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
    motADevine=motadev; 
    
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
      
    }
    majlettreniveau();

    }

    function majlettreniveau(){
      motadev=motADevine
      const motActuel= getMotActuel();
      var lettre;
      if(motActuel && motActuel.length<size){
    if(niveau ==1){
      if(index%size==0){
        lettre = motadev[0];
        const placeCourante=document.getElementById(String(index+size-1));
        placeCourante.textContent=motadev[size-1];
      }
      majTableau(lettre,size)
    }
    if(niveau ==2){
      if(index%size ==0){
        lettre = motadev[0];
        
      }
      majTableau(lettre,size)
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
          var appel=fetch('/checkmot?lang='+langue+"&essais="+mot)//passage du mot et de sa langue au serveur
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
                majlettreniveau();
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
                  startConfetti();
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
                majlettreniveau();
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

  var maxParticleCount = 150; //set max confetti count
  var particleSpeed = 2; //set the particle animation speed
  var startConfetti; //call to start confetti animation
  var stopConfetti; //call to stop adding confetti
  var toggleConfetti; //call to start or stop the confetti animation depending on whether it's already running
  var removeConfetti; //call to stop the confetti animation and remove all confetti immediately
  
  (function() {
    startConfetti = startConfettiInner;
    stopConfetti = stopConfettiInner;
    toggleConfetti = toggleConfettiInner;
    removeConfetti = removeConfettiInner;
    var colors = ["DodgerBlue", "OliveDrab", "Gold", "Pink", "SlateBlue", "LightBlue", "Violet", "PaleGreen", "SteelBlue", "SandyBrown", "Chocolate", "Crimson"]
    var streamingConfetti = false;
    var animationTimer = null;
    var particles = [];
    var waveAngle = 0;
    
    function resetParticle(particle, width, height) {
      particle.color = colors[(Math.random() * colors.length) | 0];
      particle.x = Math.random() * width;
      particle.y = Math.random() * height - height;
      particle.diameter = Math.random() * 10 + 5;
      particle.tilt = Math.random() * 10 - 10;
      particle.tiltAngleIncrement = Math.random() * 0.07 + 0.05;
      particle.tiltAngle = 0;
      return particle;
    }
  
    function startConfettiInner() {
      var width = window.innerWidth;
      var height = window.innerHeight;
      window.requestAnimFrame = (function() {
        return window.requestAnimationFrame ||
          window.webkitRequestAnimationFrame ||
          window.mozRequestAnimationFrame ||
          window.oRequestAnimationFrame ||
          window.msRequestAnimationFrame ||
          function (callback) {
            return window.setTimeout(callback, 16.6666667);
          };
      })();
      var canvas = document.getElementById("confetti-canvas");
      if (canvas === null) {
        canvas = document.createElement("canvas");
        canvas.setAttribute("id", "confetti-canvas");
        canvas.setAttribute("style", "display:block;z-index:999999;pointer-events:none");
        document.body.appendChild(canvas);
        canvas.width = width;
        canvas.height = height;
        window.addEventListener("resize", function() {
          canvas.width = window.innerWidth;
          canvas.height = window.innerHeight;
        }, true);
      }
      var context = canvas.getContext("2d");
      while (particles.length < maxParticleCount)
        particles.push(resetParticle({}, width, height));
      streamingConfetti = true;
      if (animationTimer === null) {
        (function runAnimation() {
          context.clearRect(0, 0, window.innerWidth, window.innerHeight);
          if (particles.length === 0)
            animationTimer = null;
          else {
            updateParticles();
            drawParticles(context);
            animationTimer = requestAnimFrame(runAnimation);
          }
        })();
      }
    }
  
    function stopConfettiInner() {
      streamingConfetti = false;
    }
  
    function removeConfettiInner() {
      stopConfetti();
      particles = [];
    }
  
    function toggleConfettiInner() {
      if (streamingConfetti)
        stopConfettiInner();
      else
        startConfettiInner();
    }
  
    function drawParticles(context) {
      var particle;
      var x;
      for (var i = 0; i < particles.length; i++) {
        particle = particles[i];
        context.beginPath();
        context.lineWidth = particle.diameter;
        context.strokeStyle = particle.color;
        x = particle.x + particle.tilt;
        context.moveTo(x + particle.diameter / 2, particle.y);
        context.lineTo(x, particle.y + particle.tilt + particle.diameter / 2);
        context.stroke();
      }
    }
  
    function updateParticles() {
      var width = window.innerWidth;
      var height = window.innerHeight;
      var particle;
      waveAngle += 0.01;
      for (var i = 0; i < particles.length; i++) {
        particle = particles[i];
        if (!streamingConfetti && particle.y < -15)
          particle.y = height + 100;
        else {
          particle.tiltAngle += particle.tiltAngleIncrement;
          particle.x += Math.sin(waveAngle);
          particle.y += (Math.cos(waveAngle) + particle.diameter + particleSpeed) * 0.5;
          particle.tilt = Math.sin(particle.tiltAngle) * 15;
        }
        if (particle.x > width + 20 || particle.x < -20 || particle.y > height) {
          if (streamingConfetti && particles.length <= maxParticleCount)
            resetParticle(particle, width, height);
          else {
            particles.splice(i, 1);
            i--;
          }
        }
      }
    }
  })();

  