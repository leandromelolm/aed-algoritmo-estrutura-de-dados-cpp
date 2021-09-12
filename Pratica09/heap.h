
#ifndef HEAP_H_
#define HEAP_H_

template <class T>
class Heap {
private:
	int size, cap;
	int * array;
	int * pos;
	T * weight;

public:
	Heap(int cap, T * weight) {
		this->size = cap;
		this->cap = cap;
		this->weight = weight;
		array = new int[cap];
		pos = new int[cap];

		for (int i = 0; i < cap; i++) {
			array[i] = i;
			pos[i] = i;
		}

		this->heapify();
	}

	~Heap() {
		delete [] array;
		delete [] pos;
	}

	int dequeue() {
		int max = array[0];
		array[0] = array[size - 1];
		int j = 0;

		while (j < size) {
			int l = 2 * j + 1;
			int r = 2 * j + 2;
			int n = j;

			if (l < size && (weight[array[n]] > weight[array[l]])) n = l;

			if (r < size && (weight[array[n]] > weight[array[r]])) n = r;

			if (j != n) {
				hswap(j, n);
				j = n;
			} else break;
		}

		size--;

		return max;
	}

	void decrease(int idx) {
		int j = pos[idx];
		while (j > 0 && (weight[array[j]] < weight[array[(j - 1) / 2]])) {
			hswap(j, (j - 1) / 2);
			j = (j - 1) / 2;
		}
	}

	int empty() { return size == 0; }

private:
	void hswap(int x, int y) {
		swap(array[x], array[y]);
		swap(pos[array[x]], pos[array[y]]);
	}

	void heapify() {
		for (int i = 1; i < size; i++) {
			int j = i;
			while (j > 0 && (weight[array[j]] < weight[array[(j - 1) / 2]])) {
				hswap(j, (j - 1) / 2);
				j = (j - 1) / 2;
			}
		}
	}
};

#endif /* HEAP_H_ */
