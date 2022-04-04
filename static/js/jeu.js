  let motstentes = [[]];
  let placedispo = 1;

  let guessedWordCount = 0;

  const touches = document.querySelectorAll(".keyboard-row button");

  function motcourant() {
    const nbrmotstentes = motstentes.length;
    return motstentes[nbrmotstentes - 1];
  }

  function majmotstentes(letter) {
    const currentWordArr = motcourant();

    if (currentWordArr && currentWordArr.length < 5) {
      currentWordArr.push(letter);

      const placedispo1 = document.getElementById(String(placedispo));

      placedispo= placedispo + 1;
      placedispo1.textContent = letter;
    }
  }

  function lettresupprime() {
    const currentWordArr = motcourant();
    //const removedLetter = currentWordArr.pop();

    motstentes[motstentes.length - 1] = currentWordArr;

    const lastLetterEl = document.getElementById(String(placedispo - 1));

    lastLetterEl.textContent = "";
    placedispo = placedispo - 1;
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

      majmotstentes(lettre);
    };
}
