var stage;
var ballTrail;
var ball;
var floor;
var target;

var ballVx = 3;
var ballVy = 1;

var GRAVITY = 0.1;
var RESTITUTION = 0.8;

function init() {
  stage = new createjs.Stage("demoCanvas");

  ballTrail = new createjs.Shape();
  stage.addChild(ballTrail);

  target = new createjs.Shape();
  target.graphics.beginFill("blue").drawRect(0, 0, 40, 40);
  target.x = Math.round(Math.random() * 760);
  target.y = Math.round(Math.random() * 400);
  stage.addChild(target);


  ball = new createjs.Shape();
  ball.height = 10;
  ball.graphics.beginFill("DeepSkyBlue").drawCircle(0, 0, ball.height);
  ball.x = 100;
  ball.y = 100;
  stage.addChild(ball);

  floor = new createjs.Shape();
  floor.graphics.beginFill("red").drawRect(0, 0, 800, 10);
  floor.y = 440;
  stage.addChild(floor);



// draw a bucket


  stage.update();


  createjs.Ticker.addEventListener("tick", tick);
  createjs.Ticker.setFPS(60); // for the PCMR :P
}

function tick() {
  applyGravity();
  collisionDetect();
  moveObjects();
  ballTrail.graphics.beginFill("green").drawCircle(ball.x, ball.y, 2);
  stage.update();
}

function collisionDetect(){
  // floor
  if (ball.y + (ball.height)  > 440 ){
    ballVy = -Math.abs(ballVy * RESTITUTION);
  }

  // left wall
  if (ball.x - ball.height < 0 ){
    ballVx = Math.abs(ballVy * RESTITUTION);
  }
  // right wall

  if (ball.x + ball.height > 800 ){
    ballVx = -Math.abs(ballVy * RESTITUTION);
  }

  if (ball.x > target.x && ball.x < target.x + 40 && ball.y > target.y && ball.y < target.y + 40){
    ballVx = 0;
    ballVy = 0;
    GRAVITY = 0;
  }
}

function applyGravity() {
  ballVy += GRAVITY;
}

function moveObjects(){
  ball.x += ballVx;
  ball.y += ballVy;
}
