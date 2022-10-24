class Solution {
  public:

    int ladderLength(string beginWord, string endWord, vector < string > & wordList) {
      unordered_set < string > wordSet; // declare an unordered set

      bool isPresent = false; // to find whether end word is present in word list or not

      // Inserting all words from wordList to wordSet
      for (string word: wordList) {
        if (endWord.compare(word) == 0) // if end word is present in wordList
        {
          isPresent = true;
        }

        wordSet.insert(word); // Inserting each word in wordSet
      }

      if (isPresent == false) // if end word is not present in worrd List
        return 0;

      queue < string > q; // declare an queue, for BFS traversal
      q.push(beginWord); // push begi word into our queue

      int depth = 0; // for telling depth of the queue we are exploring

      // Implementing BFS
      while (q.empty() == false) {
        depth = depth + 1; // if one level is over increment depth

        int levelSize = q.size(); // number of words present at a level

        // travelling in each level
        while (levelSize--) {
          string curr = q.front();
          q.pop();

          // checking for all possible depth word
          for (int i = 0; i < curr.length(); i++) // for each index
          {
            string temp = curr;

            //checking out each possibility of alphabet
            for (char c = 'a'; c <= 'z'; c++) {
              temp[i] = c;

              if (curr.compare(temp) == 0) // skipping the same word
                continue;

              if (temp.compare(endWord) == 0) // if matches with end word
                return depth + 1;

              // if present in word set
              if (wordSet.find(temp) != wordSet.end()) {
                q.push(temp);
                wordSet.erase(temp);
              }
            }
          }
        }
      }

      return 0;
    }
};
