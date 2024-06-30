#include <iostream>
#include <cstring>
using namespace std;

class Furniture{
	protected:
		double weight;
    
    public:
    	Furniture(){
		}
		
    	Furniture(double w){
    		weight = w;
		}
		
		void setWeight(double w){
			weight = w;
		}
		
		double getWeight(){
			return weight;
		}
};

class Bed: virtual public Furniture{
	protected:
		int width;
	
	public:
		Bed(){
		}
		Bed(int w){
			width = w;
		}
		void sleep(){
			cout << "Sleeping......" << endl;
		}
		
		int getWidth(){
			return width;
		}
};

class Sofa: virtual public Furniture{
	protected:	
		string color;
	
	public:
		Sofa(){
		}
		Sofa(string c){
			color = c;
		}
		void watchTV(){
			cout << "Watching TV......" << endl;
		}
		
		string getColor(){
			return color;
		}
		
		void foldOut(){
			cout << "Fold out the Sofa!" << endl;
		}
};

class SleeperSofa: protected Bed, protected Sofa{
	
	public:
		SleeperSofa(double w1, int w2, string c){
			weight = w1;
			width = w2;
			color = c;
		}
		void show(){
			cout << "Sofabed weight:" << getWeight() << ", width:" 
			<< getWidth() << ", color:" << getColor() << endl;
		}
		void foldOut(){                              /*����public�̳�Bed��Sofa����������д������*/ 
			cout << "Fold out the Sofa!" << endl;
		}
		void watchTV(){
			cout << "Watching TV......" << endl;
		}
		void sleep(){
			cout << "Sleeping......" << endl;
		}                                            /*�����̳�ʹ������Ϊ������Ա���²���ֱ�ӷ���*/
};       

int main(){
	SleeperSofa ss(10, 180, "Red");
	ss.show();
	ss.watchTV();
	ss.foldOut();
	ss.sleep();
	return 0;
}
