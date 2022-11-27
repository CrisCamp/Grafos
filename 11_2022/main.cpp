#include<iostream>
#include <list>
#include"SFML\Graphics.hpp"

using namespace std;
using namespace sf;

class Graph {
    int V; //Numero de vertices
    list<int>* adj; //arreglo de listas de adyacencia
    bool* visited; //matriz de visitados.
public:
    Graph(int V); //Constructor
    void addEdge(int v, int w); //GRAFO Dirigido de v -> w
    void DFS(int v); //DFS iniciando de v
};
Graph::Graph(int V) {
    this->V = V;
    adj = new list<int>[V];
    this->visited = new bool[this->V];
    for (int i = 0; i < this->V; i++) this->visited[i] = false;
}
void Graph::addEdge(int v, int w) {
    adj[v].push_back(w); //agrega w a la posicion v
    //adj[w].push_back(v); //si fuera no dirigido
}
void Graph::DFS(int v) {
    this->visited[v] = true; //marca el nodo actual como visitado e imprimelo
    cout << "[" << v << "]" << " ";

    list<int>::iterator it;
    for (it = adj[v].begin(); it != adj[v].end(); ++it) { //nodos adyacentes
        if (!this->visited[*it]) {
            DFS(*it);
        }
    }
}

int PosicionX(int x)
{
    if (x < 0)
    {
        x = 0;
    }
    else if (x > 646)//dato obtenido al tanteo
    {
        x = 645;
    }
    return x;
}
int PosicionY(int y)
{
    if (y < 0)
    {
        y = 0;
    }
    else if (y > 276)//dato obtenido al tanteo
    {
        y = 275;
    }
    return y;
}

class Inicio
{
private:  
    int movimiento, x, y, posW; 
    Texture textura, textura1, textura2, textura3, textura4, textura5;
    Sprite sprite, sprite1, sprite2, imagen, imagen1, imagen2;
    Font font;
    Text textA, textB, textC, textD, textE, textF, textG, textH, textI;
public:
    Inicio()
    {
        posW = 0;
        movimiento = 2; //la variable movimeinto no debe ser cero, porque esta se encarga de que el movimiento de la imagen exista
        x = 0;
        y = 0;

        textura.loadFromFile("c2.jpg"); //"imagen con fondo oscuro recordar", esta parte, ya que parece que la imagen se movio unas casillas por el eje x
        textura1.loadFromFile("c3.jpg");
        textura2.loadFromFile("c4.jpg");
        textura3.loadFromFile("cofre.jpg");
        textura4.loadFromFile("screamer1.jpg");
        textura5.loadFromFile("screamer2.jpg");

        sprite.setTexture(textura);
        sprite.move(70.f, 100.f);
        sprite1.setTexture(textura1);
        sprite1.move(70.f, 100.f);
        sprite2.setTexture(textura2);
        sprite2.move(70.f, 100.f);
        imagen.setTexture(textura3);
        imagen.move(370.f, 100.f);
        imagen1.setTexture(textura4);
        imagen1.move(270.f, 100.f);
        imagen2.setTexture(textura5);
        imagen2.move(520.f, 50.f);

        font.loadFromFile("COMICATE.ttf");

        textA.setFont(font);
        textA.setString("A");
        textA.move(570.f, 95.f);

        textB.setFont(font);
        textB.setString("B");
        textB.move(570.f, 95.f);

        textC.setFont(font);
        textC.setString("C");
        textC.move(570.f, 195.f);
        
        textD.setFont(font);
        textD.setString("D");
        textD.move(570.f, 295.f);

        textE.setFont(font);
        textE.setString("E");
        textE.move(570.f, 195.f);

        textF.setFont(font);
        textF.setString("F");
        textF.move(570.f, 295.f);

        textG.setFont(font);
        textG.setString("G");
        textG.move(570.f, 295.f);

        textH.setFont(font);
        textH.setString("H");
        textH.move(570.f, 295.f);

        textI.setFont(font);
        textI.setString("I");
        textI.move(570.f, 195.f);
    }

    CircleShape Circulos (int z)
    {
        CircleShape C1(40.f);
        C1.setFillColor(sf::Color::White);
        C1.move(600.f, 75.f);
        CircleShape C2(40.f);
        C2.setFillColor(sf::Color::White);
        C2.move(600.f, 175.f);
        CircleShape C3(40.f);
        C3.setFillColor(sf::Color::White);
        C3.move(600.f, 275.f);

        if (z == 1)
        {
            return C1;
        }
        else if (z == 2)
        {
            return C2;
        }
        else if (z == 3)
        {
            return C3;
        }
    }

    void cheems(Sprite &s)
    {
        if (Keyboard::isKeyPressed(Keyboard::Up))
        {
            x = s.getPosition().x;
            y = s.getPosition().y - movimiento;
            //cout << "\n" << y;
            //cout << "\n" << x;

            s.setPosition(PosicionX(x), PosicionY(y));
        }
        if (Keyboard::isKeyPressed(Keyboard::Down))
        {
            x = s.getPosition().x;
            y = s.getPosition().y + movimiento;
            //cout << "\n" << y;
            //cout << "\n" << x;

            s.setPosition(PosicionX(x), PosicionY(y));
        }
        if (Keyboard::isKeyPressed(Keyboard::Left))
        {
            x = s.getPosition().x - movimiento;
            y = s.getPosition().y;
            //cout << "\n" << y;
            //cout << "\n" << x;

            s.setPosition(PosicionX(x), PosicionY(y));
        }
        if (Keyboard::isKeyPressed(Keyboard::Right))
        {
            x = s.getPosition().x + movimiento;
            y = s.getPosition().y;
            //cout << "\n" << y;
            //cout << "\n" << x;

            s.setPosition(PosicionX(x), PosicionY(y));
        }
    }

    void recorrido(int posV, int posW)
    {
        int V = 9;
        Graph G(V);
        cout << "[V] -> [W]:\t";
        G.addEdge(posV, posW);
        int src = posV;
        G.DFS(src);
        cout << "\n";
    }

    void run0()
    {
        RenderWindow window(VideoMode(800, 450), "SFML works!");

        while (window.isOpen())
        {
            Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::B))
            {
                posW = 1;
                recorrido(posV, posW);
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::C))
            {
                posW = 2;
                recorrido(posV, posW);
                window.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                posW = 3;
                recorrido(posV, posW);
                window.close();
            }
            window.clear();
            window.draw(sprite);
            window.draw(textB);
            window.draw(Circulos(1));
            window.draw(textC);
            window.draw(Circulos(2));
            window.draw(textD);
            window.draw(Circulos(3));
            window.display();

            cheems(sprite);
        } //
        //B, C, D

        if (posW == 1)
        {
            run1();
        }
        else if (posW == 2)
        {
            run2();
        }
        else if (posW == 3)
        {
            run3();
        }
    }

    void run1()
    {
        RenderWindow window2(sf::VideoMode(800, 450), "SFML works!");

        while (window2.isOpen())
        {
            Event event;
            while (window2.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window2.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                posW = 0;
                recorrido(posV, posW);
                window2.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                posW = 4;
                recorrido(posV, posW);
                window2.close();
            }
            window2.clear();
            window2.draw(sprite);
            window2.draw(textA);
            window2.draw(Circulos(1));
            window2.draw(textE);
            window2.draw(Circulos(2));
            window2.display();

            cheems(sprite);
        }

        if (posW == 0)
        {
            run0();
        }
        else if (posW == 4)
        {
            run4();
        }
    }

    void run2()
    {
        RenderWindow window3(VideoMode(800, 450), "SFML works!");

        while (window3.isOpen())
        {
            Event event;
            while (window3.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window3.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                posW = 0;
                recorrido(posV, posW);
                window3.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::E))
            {
                posW = 4;
                recorrido(posV, posW);
                window3.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::H))
            {
                posW = 7;
                recorrido(posV, posW);
                window3.close();
            }
            window3.clear();
            window3.draw(sprite);
            window3.draw(textA);
            window3.draw(Circulos(1));
            window3.draw(textE);
            window3.draw(Circulos(2));
            window3.draw(textH);
            window3.draw(Circulos(3));
            window3.display();

            cheems(sprite);
        }
        if (posW == 0)
        {
            run0();
        }
        else if (posW == 4)
        {
            run4();
        }
        else if (posW == 7)
        {
            // Nodo 7 //

            RenderWindow window8(VideoMode(800, 450), "SFML works!");

            while (window8.isOpen())
            {
                Event event;
                while (window8.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window8.close();
                    //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        //window.close();
                }
                int posV = posW;
                if (Keyboard::isKeyPressed(Keyboard::C))
                {
                    posW = 3;
                    recorrido(posV, posW);
                    window8.close();
                }
                window8.clear();
                window8.draw(imagen1);
                window8.draw(sprite1);
                window8.draw(textC);
                window8.draw(Circulos(2));
                window8.display();

                cheems(sprite1);
            }
            if (posW == 3)
            {
                run2();
            }
        }

    }

    void run3()
    {
        RenderWindow window4(sf::VideoMode(800, 450), "SFML works!");

        while (window4.isOpen())
        {
            Event event;
            while (window4.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window4.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::A))
            {
                posW = 0;
                recorrido(posV, posW);
                window4.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::F))
            {
                posW = 5;
                recorrido(posV, posW);
                window4.close();
            }
            window4.clear();
            window4.draw(sprite);
            window4.draw(textA);
            window4.draw(Circulos(1));
            window4.draw(textF);
            window4.draw(Circulos(3));
            window4.display();

            cheems(sprite);
        }
        if (posW == 0)
        {
            run0();
        }
        else if (posW == 5)
        {
            run5();
        }
    }

    void run4()
    {
        // nodo 4 //
        RenderWindow window5(VideoMode(800, 450), "SFML works!");

        while (window5.isOpen())
        {
            Event event;
            while (window5.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window5.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::B))
            {
                posW = 1;
                recorrido(posV, posW);
                window5.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::C))
            {
                posW = 2;
                recorrido(posV, posW);
                window5.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::G))
            {
                posW = 6;
                recorrido(posV, posW);

                //Final 1 XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX

                window5.close();
            }
            window5.clear();
            window5.draw(sprite);
            window5.draw(textB);
            window5.draw(Circulos(1));
            window5.draw(textC);
            window5.draw(Circulos(2));
            window5.draw(textG);
            window5.draw(Circulos(3));
            window5.display();

            cheems(sprite);
        }
        if (posW == 1)
        {
            run1();
        }
        else if (posW == 2)
        {
            run2();
        }
        else if (posW == 6)
        {
            // nodo 6 //

            RenderWindow window7(VideoMode(800, 450), "SFML works!");

            while (window7.isOpen())
            {
                Event event;
                while (window7.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window7.close();
                    //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        //window.close();
                }
                int posV = posW;
                if (Keyboard::isKeyPressed(Keyboard::E))
                {
                    posW = 4;
                    recorrido(posV, posW);
                    window7.close();
                }
                window7.clear();
                window7.draw(imagen);
                window7.draw(sprite2);
                window7.draw(textE);
                window7.draw(Circulos(2));
                window7.display();

                cheems(sprite2);
            }
            if (posW == 4)
            {
                run4();
            }
        }
    }

    void run5()
    {
        RenderWindow window9(VideoMode(800, 450), "SFML works!");

        while (window9.isOpen())
        {
            Event event;
            while (window9.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window9.close();
                //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                    //window.close();
            }
            int posV = posW;
            if (Keyboard::isKeyPressed(Keyboard::D))
            {
                posW = 3;
                recorrido(posV, posW);
                window9.close();
            }
            if (Keyboard::isKeyPressed(Keyboard::I))
            {
                posW = 8;
                recorrido(posV, posW);
                window9.close();
            }
            window9.clear();
            window9.draw(sprite);
            window9.draw(textI);
            window9.draw(Circulos(2));
            window9.draw(textD);
            window9.draw(Circulos(3));
            window9.display();

            cheems(sprite);
        }
        if (posW == 3)
        {
            run3();
        }
        else if (posW == 8)
        {
            // nodo 8 //

            RenderWindow window10(VideoMode(800, 450), "SFML works!");

            while (window10.isOpen())
            {
                Event event;
                while (window10.pollEvent(event))
                {
                    if (event.type == sf::Event::Closed)
                        window10.close();
                    //if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
                        //window.close();
                }
                int posV = posW;
                if (Keyboard::isKeyPressed(Keyboard::F))
                {
                    posW = 5;
                    recorrido(posV, posW);
                    window10.close();
                }
                window10.clear();
                window10.draw(imagen2);
                window10.draw(sprite1);
                window10.draw(textF);
                window10.draw(Circulos(3));
                window10.display();

                cheems(sprite1);
            }
            if (posW == 5)
            {
                run5();
            }
        }
    }

};

int main()
{
    Inicio* run = new Inicio();
    run->run0();
}