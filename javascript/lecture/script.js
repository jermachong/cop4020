// script.js
document.addEventListener("DOMContentLoaded", function () {
  // Select the button and input field
  const button = document.getElementById("mybutton");
  const nameInput = document.getElementById("inputv");
  // Add an event listener to the button
  button.addEventListener("click", function () {
    // Get the value from the input field
    const name = nameInput.value;
    // Show an alert with the name entered
    alert("You entered: " + name);
  });
});
