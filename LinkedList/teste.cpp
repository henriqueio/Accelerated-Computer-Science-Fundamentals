// first: sort the two lists
if (!left.isSorted()) {
  // std::cout << "** Sorting left list **" << std::endl;
  left.mergeSort();
}
if (!right.isSorted()) {
  // std::cout << "** Sorting right list **" << std::endl;
  right.mergeSort();
}

// Iterate through left and right, popping off the lower one to the new merge
// linked list
while ((left.size() + right.size()) > 0) {
  // std::cout << "*** Merging with size = " << (left.size() + right.size() )
  // << std::endl;

  if (left.empty()) {
    // std::cout << "* Left is empty.  Adding from right: " << right.front()
    // << std::endl;
    merged.pushBack(right.front());
    right.popFront();
  } else if (right.empty()) {
    // std::cout << "* Right is empty.  Adding from left: " << left.front() <<
    // std::endl;
    merged.pushBack(left.front());
    left.popFront();
  } else {
    if (left.front() <= right.front()) {
      // std::cout << "* Left smaller than right, adding from left: " <<
      // left.front() << std::endl;
      merged.pushBack(left.front());
      left.popFront();
    } else {
      // std::cout << "* Right smaller than left, adding from right: " <<
      // right.front() << std::endl;
      merged.pushBack(right.front());
      right.popFront();
    }
  }
}