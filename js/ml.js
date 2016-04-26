var stage;
var ballTrail;
var ball;
var floor;
var target;
var aimLine;

var ballVx;
var ballVy;
var ballFired;

var MAX_V = 10;

var fireVel;
var fireAng;

var timeBegan;
var attempts = 0;
var succesfulHits = 0;

var elapsedTimeText;
var attemptsText;
var successfulHitsText;
var aimText;

var GRAVITY = 0.1;
var RESTITUTION = 0.8;
var AIM_SCALER = 40;

function init() {
  stage = new createjs.Stage("demoCanvas");
  createjs.Ticker.addEventListener("tick", tick);
  createjs.Ticker.setFPS(60); // for the PCMR :P
  reset();
}

function tick() {
  if (ballFired){
    applyGravity();
    collisionDetect();
    moveObjects();
    ballTrail.graphics.beginFill("green").drawCircle(ball.x, ball.y, 2);

    elapsedTimeText.text = ((createjs.Ticker.getTime() - timeBegan) / 1000).toFixed(2) + " s";

    if (createjs.Ticker.getTime() - timeBegan > 10 * 1000){
      reset();
    }
  }else{
    fireVel = Math.hypot(stage.mouseX - 40,stage.mouseY - 400) / AIM_SCALER;
    fireAng = Math.atan2(-(stage.mouseY - 400), stage.mouseX - 40)/Math.PI * 180;

    aimText.x = stage.mouseX;
    aimText.y = stage.mouseY;
    aimText.text = "Velocity: " + fireVel.toFixed(2)+" Angle: "+fireAng.toFixed(2);

    aimLine.graphics.clear();
    aimLine.graphics.setStrokeStyle(3);
    aimLine.graphics.beginStroke("red")
    aimLine.graphics.moveTo(stage.mouseX, stage.mouseY);
    aimLine.graphics.lineTo(40,400);
    aimLine.graphics.endStroke();

    elapsedTimeText.text = "0 s";
  }

  successfulHitsText.text = "Succesful attempts : " + succesfulHits + " (" + (succesfulHits/attempts * 100).toFixed(0) + "%)";
  attemptsText.text = "Attempts : " + attempts;

  stage.update();
}

function collisionDetect(){
  // floor
  if (ball.y + (ball.height)  > 440 ){
    ballVy = -Math.abs(ballVy * RESTITUTION);
    ball.y = 440 - (ball.height + 1);
  }

  // left wall
  if (ball.x - ball.height < 0 ){
    ballVx = Math.abs(ballVy * RESTITUTION);
    ball.x = ball.height + 1;
  }
  // right wall

  if (ball.x + ball.height > 800 ){
    ballVx = -Math.abs(ballVy * RESTITUTION);
    ball.x = 800 - (ball.height + 1);

  }

  if (ball.x > target.x && ball.x < target.x + 40 && ball.y > target.y && ball.y < target.y + 40){
    succesfulHits += 1;
    reset();
  }
}

function applyGravity() {
  ballVy += GRAVITY;
}

function moveObjects(){
  ball.x += ballVx;
  ball.y += ballVy;
}

function reset(){
  attempts += 1;
  stage.removeAllChildren();

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
  stage.addChild(ball);

  floor = new createjs.Shape();
  floor.graphics.beginFill("red").drawRect(0, 0, 800, 10);
  floor.y = 440;
  stage.addChild(floor);

  aimLine = new createjs.Shape();
  stage.addChild(aimLine);

  elapsedTimeText = new createjs.Text("", "20px Arial", "#000000");
  stage.addChild(elapsedTimeText);
  attemptsText = new createjs.Text("", "20px Arial", "#000000");
  stage.addChild(attemptsText);
  attemptsText.x = 75;
  successfulHitsText = new createjs.Text("", "20px Arial", "#000000");
  stage.addChild(successfulHitsText);
  successfulHitsText.x = 200;

  aimText = new createjs.Text("", "20px Arial", "#000000");
  stage.addChild(aimText);

  ballFired = false;
  ball.x = 40;
  ball.y = 400;



  stage.update();

  stage.addEventListener("stagemouseup", function(event) {
    timeBegan = createjs.Ticker.getTime();
    ballFired = true;
    ballVx = (stage.mouseX - 40) / AIM_SCALER;
    ballVy = (stage.mouseY - 400) / AIM_SCALER;
    stage.removeChild(aimText);
    stage.removeChild(aimLine);
    stage.removeAllEventListeners("stagemouseup");
  })
}
