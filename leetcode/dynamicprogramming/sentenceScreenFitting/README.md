# 418. Sentence Screen Fitting

- source: https://leetcode.com/problems/sentence-screen-fitting/

## Approach
```
    use a greedy approach: looking for MAXIMUM time the given sentence can be fitted
```

## Complexity
```
    O(n)
    
    Worst O(rows * cols)
    O(1)
```

## Explanation
```
    len: the total length of s with white space
    count: how many valid chars have been put so far
    goal is to find: count/len
    
    If it’s space, means we successfully fill the first row. 
    If it’s not space, then it means it’s in middle of words. We check one step left to see if it’s space. If it’s space then we just keep the current count. If not, we have to keep moving left one char by one char, (at the same time decrease the count) until we find a space.
```

```
	public int wordsTyping(String[] sentence, int rows, int cols) {

		String sent = String.join(" ", sentence) + " "; // "hello world "
		int pos = 0;
		int totallen = sent.length(); // 12

		for (int i = 0; i < rows; i++) {
			pos += cols; // 8->6+8(14)

			// case 1) for characters
			// (Jump to the STARTING-POSITION of the next word)
			while (pos >= 0 && sent.charAt(pos % totallen) != ' ') { // 8 % 12 = 8->
																		// 14%12=2
				pos--; // 8->5->12
			}

			// case 2)
			pos++; // 5->6->2
		}

		return pos / totallen; // 2/
	}
```
