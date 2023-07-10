/* TP, 2018/2019, Zadaća 1, Zadatak 1

	NAPOMENA: ulaz/izlaz za zadatke je specificiran
	javnim autotestovima. Zalbe za ne analiziranje testova
	se ne uvazavaju!

	NAPOMENA: nece svi (javni) testovi sa zamgera biti
	dostupni na c9.
*/
#include <iostream>
#include <vector>
std::vector<int>Vektor(long long a)
{
	std::vector<int>v;
	while(a>0)
	{
		int broj=a%10;
		v.push_back(broj);
		a=a/10;
	}
	return v;

}

std::vector<int> PalindromskaOtpornost(std::vector<int> v)
{
	std::vector<int>potp;
	int otpornost;
	int broj;
	for(int i=0;i<v.size();i++)
	{
		otpornost=0;
		long long x=v.at(i);
		if(x<0)
		x=x*(-1);
		std::vector<int>broj2=Vektor(x);
		int provjera=1;
		int otp=0;
		for(int h=0;h<broj2.size()/2;h++)
		{
			if(broj2.at(h)!=broj2.at(broj2.size()-1-h))
			{
			provjera=0;
			break;
			}
		}
		if(provjera)
		{
			otp=1;
			potp.push_back(otpornost);
		}
		//int otp=0;
		while(otp==0)
		{
			otpornost+=1;
			long long broj1=0;
			broj1=0;
			if(x<0)
			x=x*(-1);
			long long z=x;
			while(x>0)
			{
				broj=x%10;
				broj1=broj1*10+broj;
				x=x/10;
			}
			long long y=z+broj1;
			long long a=y;
			//int j=0;
			std::vector<int>cifr=Vektor(a);
			otp=1;
			for(int k=0;k<(cifr.size()/2);k++)
			{
				if(cifr.at(k)!=cifr.at(cifr.size()-1-k))
				{
					otp=0;
					break;
				}
			}
			if(otp==1)
			{
				potp.push_back(otpornost);
				break;
			}
			else
			{
				x=y;
			}

		}
	}
	return potp;
}
int main ()
{
	std::cout<<"Koliko zelite unijeti elemenata: ";
	int n;
	std::cin>>n;
	std::vector<int>a;
	std::cout<<"Unesite elemente: ";
	for(int i=0;i<n;i++)
	{
		long x;
		std::cin>>x;
		a.push_back(x);
	}
	std::vector<int>v=PalindromskaOtpornost(a);
	for(int g=0;g<v.size();g++)
	{
		std::cout<<"Palindromska otpornost broja "<<a.at(g)<<" iznosi "<<v.at(g);
		if(g<v.size()-1)
		std::cout<<"  ";
		else
		std::cout<<" ";
		std::cout<<std::endl;
	}
	return 0;
}
