document.addEventListener("DOMContentLoaded", () => {
    let mot='LUCIE'
  
    const touches = document.querySelectorAll(".keyboard-row button");
  
    for (let i = 0; i < touches.length; i++) {
        touches[i].onclick = ({ target }) => {
          const lettre = target.getAttribute("data-key");
          console.log(lettre)
          if (lettre === "entre") {
            print(mot);
            return;
          }
    
          if (lettre === "supprimer") {
            return;
          }
    
        };
    };
    
  
  });
  