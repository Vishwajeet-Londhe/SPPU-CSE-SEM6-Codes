let equal_pressed = 0;
let button_input = document.querySelectorAll(".input-button");

let input = document.getElementById("input");
let equal = document.getElementById("equal");
let clr = document.getElementById("clr");
let del = document.getElementById("del");
let square = document.getElementById("square");  // New square button

window.onload = () => {
  input.value = "";
};

button_input.forEach((button_class) => {
  button_class.addEventListener("click", () => {
    if (equal_pressed == 1) {
      input.value = "";
      equal_pressed = 0;
    }
    input.value += button_class.value;
  });
});

// Operation = (Evaluate)
equal.addEventListener("click", () => {
  equal_pressed = 1;
  let inp_val = input.value;
  try {
    // Evaluate user's input
    let solution = eval(inp_val);
    // True for natural numbers
    // False for decimals
    if (Number.isInteger(solution)) {
      input.value = solution;
    } else {
      input.value = solution.toFixed(2);
    }
  } catch (err) {
    // If user has entered invalid input
    alert("Invalid Input");
  }
});

// Operation Clear
clr.addEventListener("click", () => {
  input.value = "";
});

// Operation Delete (Backspace)
del.addEventListener("click", () => {
  input.value = input.value.substr(0, input.value.length - 1);
});

// Operation Square (new functionality)
square.addEventListener("click", () => {
  let inp_val = input.value;
  if (inp_val) {
    input.value = Math.pow(parseFloat(inp_val), 2); // Square the number
  } else {
    alert("Please enter a number to square.");
  }
});

