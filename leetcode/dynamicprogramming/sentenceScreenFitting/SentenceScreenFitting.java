package practices.dp.sentenceScreenFitting;

public class SentenceScreenFitting {

	public static void main(String[] args) {
		SentenceScreenFitting b = new SentenceScreenFitting();
		String[] sentence = new String[] { "hello", "world" };
		b.wordsTyping(sentence, 2, 8);
	}

	public int wordsTyping(String[] sentence, int rows, int cols) {

		String sent = String.join(" ", sentence) + " ";
		int pos = 0;
		int totallen = sent.length();

		for (int i = 0; i < rows; i++) {
			pos += cols;
			while (pos >= 0 && sent.charAt(pos % totallen) != ' ') {
				pos--;
			}
			pos++;
		}

		return pos / totallen;
	}
}
