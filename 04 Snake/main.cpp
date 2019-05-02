#include <SFML/Graphics.hpp>
#include <time.h>
using namespace sf;

int N = 30, M = 20;
int size = 16;
int w = size * N;
int h = size * M;

int dir, num = 4;

void
Tick()
{
  for (int i = num; i > 0; --i) {
    s[i].x = s[i - 1].x;
    s[i].y = s[i - 1].y;
  }

  if (dir == 0)
    s[0].y += 1;
  if (dir == 1)
    s[0].x -= 1;
  if (dir == 2)
    s[0].x += 1;
  if (dir == 3)
    s[0].y -= 1;

  if ((s[0].x == f.x) && (s[0].y == f.y)) {
    num+=2;
    f.x = rand() % N;
    f.y = rand() % M;
  }

  if ((s[0].x == f2.x) && (s[0].y == f2.y)) {
    num++;
    f2.x = rand() % N;
    f2.y = rand() % M;
  }

  if (s[0].x > N)
    s[0].x = 0;
  if (s[0].x < 0)
    s[0].x = N;
  if (s[0].y > M)
    s[0].y = 0;
  if (s[0].y < 0)
    s[0].y = M;

  for (int i = 1; i < num; i++)
    if (s[0].x == s[i].x && s[0].y == s[i].y)
      num = 4;
}

struct event_listener
{
	//window events
	virtual void on_close(){}
	virtual void on_gain_focus(){}
	virtual void on_lose_focus(){}
	virtual void on_resize(sf::Event::SizeEvent){}
	
	//keyboard Events
	virtual void on_key_press(sf::Event::KeyEvent){}
	virtual void on_key_release(sf::Event::KeyEvent){}
	
};


struct event_source
{
	event_source(sf::Window &w) : window(&w){}
	
	void poll()
	{
		sf::Event e;
		while(window->pollEvent(e))
			process(e);
	}
	
	void process(sf::Event const& e)
	{
		switch(e.type) {
		case Event::Closed:
			return notify([e](event_listener* l) {l->on_close(); });
			
		case Event::Resized:
			return notify([e](event_listener* l) {l->on_resize(e.size); });
			
		case Event::KeyPressed:
			return notify([e](event_listener* l) {l->on_key_press(e.key); });
		
		case Event::KeyReleased:
			return notify([e](event_listener* l) {l->on_key_release(e.key) });
		default:
			break;
		}
	}
	
	template<typename F>
	void notify (F fn)
	{
		for(event_listener* l : listeners)
			fn(l);
	}
	
	sf::Window* window;
	
	std::vector<event_listener*> listeners;
};

struct snake_app : event_listener
{
	snake_app() : 
		prng(std::random_device()()),
		window(VideoMode(w,h), "Snake Game!),
		grid(prng)
	{
		window.setFrameRateLimit(120);
	}
	
	void on_close() override
	{
		window.close();
	}
	
	void on_key_press(sf::Event::KeyEvent) override
	{
		if(e.button == Keyboard::Left)
			dir = 1;
		if(e.button == Keyboard::Right)
			dir = 2;
	    if(e.button == Keyboard::Up)
     		dir = 3;
    	if(e.button == Keyboard::Down)
      		dir = 0;
	}
};

struct debug_listener : event_listener
{
	debug_listener(snake_app& a)
		: app(&a)
	{}
	
	void on_close() override
	{
		std::cerr << "closing...\n";
	}
		
	snake_app* app;
};
 
int
main()
{

	snake_app app;
	debug_listener debug(app)
	
	event_source events(app.window);
	events.listen(app);
	events.listen(debug);
	
	while(app.is_open())
		events.poll();

 /* Texture t1, t2, t3;
  t1.loadFromFile("images/white.png");
  t2.loadFromFile("images/green.png");
  t3.loadFromFile("images/red.png");

  Sprite sprite1(t1);
  Sprite sprite2(t2);
  Sprite sprite3(t3);

  Clock clock;
  float timer = 0, delay = 0.1;

  f.x = 10;
  f.y = 10;

  f2.x = 15;
  f2.y = 15;

  while (window.isOpen()) {
    float time = clock.getElapsedTime().asSeconds();
    clock.restart();
    timer += time;

    Event e;
    while (window.pollEvent(e)) {
      if (e.type == Event::Closed)
        window.close();
    }


    if (timer > delay) {
      timer = 0;
      Tick();
    }

    ////// draw  ///////
    window.clear();

    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
        sprite1.setPosition(i * size, j * size);
        window.draw(sprite1);
      }

    for (int i = 0; i < num; i++) {
      sprite2.setPosition(s[i].x * size, s[i].y * size);
      window.draw(sprite2);
    }

    sprite2.setPosition(f.x * size, f.y * size);
    window.draw(sprite2);

    for (int i = 0; i < num; i++) {
      sprite3.setPosition(s[i].x * size, s[i].y * size);
      window.draw(sprite3);
    }

    sprite3.setPosition(f2.x * size, f2.y * size);
    window.draw(sprite3);

    window.display();
  }


  return 0;
}
