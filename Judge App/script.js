// Get references to elements in the HTML document
const teamList = document.getElementById("team-list");
const scoreModal = document.getElementById("score-modal");
const closeBtn = document.getElementById("close-modal");
const selectedTeam = document.getElementById("selected-team");
const scoreForm = document.getElementById("score-form");
const criterionSelect = document.getElementById("criterion");
const scoreInput = document.getElementById("score");

// Event listener for team buttons
teamList.addEventListener("click", (e) => {
  if (e.target.classList.contains("team-button")) {
    // Show the scoring modal
    scoreModal.style.display = "block";

    // Get the team name from the clicked button
    const teamName = e.target.getAttribute("data-team");

    // Set the selected team name in the modal
    selectedTeam.textContent = teamName;
  }
});

// Event listener for the close button on the modal
closeBtn.addEventListener("click", () => {
  // Hide the scoring modal
  scoreModal.style.display = "none";

  // Clear the selected team and form inputs
  selectedTeam.textContent = "";
  scoreForm.reset();
});

// Event listener for the score form submission
scoreForm.addEventListener("submit", (e) => {
  e.preventDefault();

  // Get the selected criterion and score
  const selectedCriterion = criterionSelect.value;
  const selectedScore = scoreInput.value;

  // You can add code here to update the Google Sheets or perform any scoring logic

  // For now, simply log the selected data
  console.log("Selected Team: " + selectedTeam.textContent);
  console.log("Selected Criterion: " + selectedCriterion);
  console.log("Selected Score: " + selectedScore);

  // Hide the scoring modal
  scoreModal.style.display = "none";

  // Clear the selected team and form inputs
  selectedTeam.textContent = "";
  scoreForm.reset();
});
