document.addEventListener("DOMContentLoaded", () => {
  motCourant();
  let motsTentes = [[]];
  let placeDispo = 1;

  let guessedWordCount = 0;

  const touches = document.querySelectorAll(".keyboard-row button");

  function motCourant() {
    const nbrMotsTentes = motsTentes.length;
    return motsTentes[nbrMotsTentes - 1];
  }

  function majMotsTentes(lettre) {
    const currentWordArr = motCourant();

    if (currentWordArr && currentWordArr.length < 5) {
      currentWordArr.push(lettre);

      const placeDispo1 = document.getElementById(String(placeDispo));

      placeDispo= placeDispo + 1;
      placeDispo1.textContent = lettre;
    }
  }

});

  function lettresupprime() {
    const currentWordArr = motCourant();
    //const removedlettre = currentWordArr.pop();

    motsTentes[motsTentes.length - 1] = currentWordArr;

    const derLettre1 = document.getElementById(String(placeDispo - 1));

    derLettre1.textContent = "";
    placeDispo = placeDispo - 1;
  }

  for (let i = 0; i < touches.length; i++) {
    touches[i].onclick = ({ target }) => {
      const lettre = target.getAttribute("data-key");

      //if (lettre === "entre") {
       // handleSubmitWord();
       // return;
      //}

      if (lettre === "supprimer") {
        lettresupprime();
        return;
      }

      majMotsTentes(lettre);
    };
}
