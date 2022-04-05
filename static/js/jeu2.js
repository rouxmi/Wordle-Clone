document.addEventListener("DOMContentLoaded", () => {
    let motADevine='LUCIE';
    let index=0;
    const touches = document.querySelectorAll(".keyboard-row button");
   
    let motsTentees=[[]]

    function getMotActuel(){
      return motsTentees[motsTentees.length-1];
    }

    function majTableau(letter, size){
      const motActuel= getMotActuel();
      if(motActuel && motActuel.length<size){
        motActuel.push(letter);
        const placeCourante=document.getElementById(String(index));
        index=index+1;
        placeCourante.textContent=letter;
      }
    }

    function gestionEntree(){
      const motActuel=getMotActuel();
      if(motActuel.length<size){
        window.alert("Ton mot est trop petit");
      }
      else{mot=motActuel.join("");
      if(mot==motADevine){
        window.alert("BRAVO");
      }
      else{
        if(motsTentees.length<nbrEssais){
          motsTentees.push([]);
        }
        else{
          window.alert("tu as réalisé trop d'essais");
        }
      }
    }
    }

    function gestionSupprime(){
      const motActuel=getMotActuel();
      if(motActuel.length>0){
        motActuel.pop();
        const placeCourante=document.getElementById(String(index-1));
        index=index-1;
        placeCourante.textContent="";
      }
    }
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
          majTableau(event.key,size);
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
  