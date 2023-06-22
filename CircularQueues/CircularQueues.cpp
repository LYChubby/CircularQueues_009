#include <iostream>
using namespace std;

class Queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	Queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a Number : ";
		cin >> num;
		cout << endl;

		// Cek Apakah Antrian Penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueue Overflow\n";
			return;
		}

		// Cek Apakah Antrian Kosong
		if (FRONT == -1) {
			FRONT = 0;
			REAR = 0;
		}
		else {
			// Jika REAR Berada Di Posisi Terakhir Array, Kembali Ke Awal Array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		// Cek Apakah Antrian Kosong
		if (FRONT == -1) {
			cout << "Queue Underflow\n";
			return;
		}
		cout << "\nThe Element Deleted From Queue Is : " << queue_array[FRONT] << "\n";

		// Cek Jika Antrian Hanya Memiliki Satu Element
		if (FRONT = REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			// Jika Elemen Yang Dihapus Berada Diposisi Terakhir Array, Kembali Ke Awal Array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		// Cek Apakah Antrian Kosong
		if (FRONT == -1) {
			cout << "Queue Is Empty\n";
			return;
		}

		cout << "\nElement In The Queue Are : \n";

		// Jika FRONT_Position <= REAR_Postion, Iterasi Dari FORNT Hingga REAR
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			// Jika FRONT_Position > REAR_Position, Iterasi Dari FRONT Hingga Akhir Array
			while (FRONT_position <= max - 1) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}

			FRONT_position = 0;

			// Iterasi Dari Awal Array Hinga REAR
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};