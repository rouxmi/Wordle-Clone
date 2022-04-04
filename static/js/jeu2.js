document.addEventListener("DOMContentLoaded", () => {
    let mot='LUCIE';
    let index=0;
    const touches = document.querySelectorAll(".keyboard-row button");
   
    let motsTentees=[[]]
    let nbrEssais=0

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
      else{
        mot=motActuel.join("");
        motsTentees.push([]);
      }
    }

    function gestionSupprime(){
      const motActuel=getMotActuel();
      motActuel.pop();
      const placeCourante=document.getElementById(String(index-1));
      index=index-1;
      placeCourante.textContent="";
    }
    
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
  