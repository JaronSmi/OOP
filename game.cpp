Event e;
    while (window.pollEvent(e)) {
      if (e.type == Event::Closed)
        window.close();
    }

    if (Keyboard::isKeyPressed(Keyboard::Left))
      dir = 1;
    if (Keyboard::isKeyPressed(Keyboard::Right))
      dir = 2;
    if (Keyboard::isKeyPressed(Keyboard::Up))
      dir = 3;
    if (Keyboard::isKeyPressed(Keyboard::Down))
      dir = 0;

    if (timer > delay) {
      timer = 0;
      Tick();
    }