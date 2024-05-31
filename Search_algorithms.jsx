import React, { useState } from "react";

function SearchAlgorithm() {
  const [inputArray, setInputArray] = useState([1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);
  const [sortedArray, setSortedArray] = useState([]);
  const [algorithm, setAlgorithm] = useState("Sequential Search");

  const handleInputChange = (event) => {
    const input = event.target.value;
    setInputArray(input.split(", ").map((num) => parseInt(num)));
  };

  const handleSort = () => {
    switch (algorithm) {
      case "Sequential Search":
        setSortedArray(inputArray.slice());
        break;
      case "Binary Search":
        setSortedArray(inputArray.slice().sort((a, b) => a - b));
        break;
      case "Insertion Sort":
        setSortedArray(inputArray.slice().sort((a, b) => a - b));
        break;
      case "Selection Sort":
        setSortedArray(inputArray.slice().sort((a, b) => a - b));
        break;
      case "Bubble Sort":
        setSortedArray(inputArray.slice().sort((a, b) => a - b));
        break;
      default:
        break;
    }
  };

  return (
    <div className="container">
      <div className="row">
        <div className="col-md-6">
          <h3>Enter the numbers separated by commas:</h3>
          <input
            type="text"
            value={inputArray.join(", ")}
            onChange={handleInputChange}
          />
        </div>
        <div className="col-md-6">
          <h3>Sorted Array:</h3>
          <input
            type="text"
            value={sortedArray.join(", ")}
            disabled
          />
        </div>
      </div>
      <div className="row">
        <div className="col-md-6">
          <h3>Select an algorithm:</h3>
          <select
            value={algorithm}
            onChange={(event) => setAlgorithm(event.target.value)}
          >
            <option value="Sequential Search">Sequential Search</option>
            <option value="Binary Search">Binary Search</option>
            <option value="Insertion Sort">Insertion Sort</option>
            <option value="Selection Sort">Selection Sort</option>
            <option value="Bubble Sort">Bubble Sort</option>
          </select>
        </div>
        <div className="col-md-6">
          <button className="btn btn-primary" onClick={handleSort}>
            Sort
          </button>
        </div>
      </div>
    </div>
  );
}

export default SearchAlgorithm;