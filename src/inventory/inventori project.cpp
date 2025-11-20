#include <iostream>
using namespace std;

class inventori{
	protected:
		string nama;
		long double stok;
		long double harga;
		string kadaluarsa;
		string kategori;
	public:
		void setBarang(string name,int stock,double price){
			stok = stock;
			nama = name;
			harga = price;
		}
		void tampilkanBarang(){
			cout<<"Nama Barang        : "<<nama<<endl;
			cout<<"Stock Barang       : "<<stok<<endl;
			cout<<"Harga Per pcs      : "<<harga<<endl;
		}
		long double totalHarga(){
			long double total;
			total = harga*stok;
			return total;
		}
		void kurangiStok(int jumlah) {
        	if (jumlah <= stok) {
            	stok -= jumlah;
            	cout << "Stok berkurang sebanyak " << jumlah << ". Sisa stok: " << stok << endl;
        	} else {
            	cout << "Stok tidak cukup!" << endl;
        	}
    	}

    	void tambahStok(int jumlah) {
        	stok += jumlah;
        	cout << "Stok bertambah sebanyak " << jumlah << ". Total stok: " << stok << endl;
    	}
};

class makanan : public inventori{
	private:
		string kadaluarsa;
	public:
		void setMakanan(string n,int s,double h, string k){
			setBarang(n,s,h);
			kadaluarsa = k;
		}
		
		void tampilkanMakanan(){
			tampilkanBarang();
			cout<<"Tanggal Kadaluarsa : "<<kadaluarsa<<endl;
			cout<<"Total Nilai Stok   : "<<totalHarga()<<endl;
			cout<<"-------------------------------------------"<<endl;
		}
};

class minuman : public inventori{
	private:
		string kadaluarsa;
	public:
		void setMinuman(string n, int s, double h, string k){
			setBarang(n,s,h);
			kadaluarsa = k;
		}
		void tampilkanMinuman(){	
			tampilkanBarang();
			cout<<"Tanggal Kadaluarsa : "<<kadaluarsa<<endl;
			cout<<"Total Nilai Stok   : "<<totalHarga()<<endl;
			cout<<"-------------------------------------------"<<endl;
		}
};

class peralatan : public inventori{
	private:
		string kategori;
	public:
		void setPeralatan(string n, int s, double h, string k){
			setBarang(n,s,h);
			kategori = k;
		}
		void tampilkanPeralatan(){
			tampilkanBarang();
			cout<<"Kategori           : "<<kategori<<endl;
			cout<<"Total Nilai Stok   : "<<totalHarga()<<endl;
			cout<<"-----------------------------------------"<<endl;
		}
};
int main(){
	makanan mk1;
	makanan mk2;
	
	minuman mn1;
	minuman mn2;
	
	peralatan p1;
	peralatan p2;
	
	mk1.setMakanan("Indomie", 100 , 3000, "19/09/2027");
	mk2.setMakanan("Roti ", 50 , 8000, "25/11/2025");
	cout<<"-----------MAKANAN------------"<<endl;
	mk1.tampilkanMakanan();
	mk2.tampilkanMakanan();
	cout<<endl;
	cout<<endl;
	
	mn1.setMinuman("Sprite", 50 , 5000 , "25/10/2027");
	mn2.setMinuman("Teh Pucuk", 100 , 4000 , "25/10/2027");
	cout<<"-----------Minuman------------"<<endl;
	mn1.tampilkanMinuman();
	mn2.tampilkanMinuman();
	cout<<endl;
	cout<<endl;
	
	p1.setPeralatan("Sapu", 15 , 30000, "Rumah Tangga");
	p2.setPeralatan("Sabun", 20, 4000, "Kesehatan");
	cout<<"----------Peralatan----------"<<endl;
	p1.tampilkanPeralatan();
	p2.tampilkanPeralatan();
	cout<<endl;
	cout<<endl;
	int d;
	cin>>d;
} 