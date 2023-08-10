extends KinematicBody2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var velocity = Vector2.ZERO
var accel = Vector2.ZERO
export var maxAccel = 50
export var maxSpeed = 500
var lerpDrag = 0.2
var maxHealth = 100
var health = maxHealth


var allowShoot:bool = true
var shootTimer:Timer
var shootInterval = 1
var bulletTemplate = preload("res://Bullet.tscn")
var bulletSpeed = 10


# Called when the node enters the scene tree for the first time.
func _ready():
	shootTimer = Timer.new()
	shootTimer.wait_time = shootInterval
	shootTimer.autostart = true
	shootTimer.connect("timeout", self, "enableShooting")
	add_child(shootTimer)


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	
	if health < 0:
		die()
	if Input.is_mouse_button_pressed(BUTTON_LEFT) and allowShoot:
		shoot()
	var dir = Input.get_vector("ui_left", "ui_right", "ui_up", "ui_down")
	if Input.is_action_pressed("ui_left"):
		accel.x = -maxAccel
	elif Input.is_action_pressed("ui_right"):
		accel.x = maxAccel
	else:
		accel.x = 0
	
	if Input.is_action_pressed("ui_up"):
		accel.y = -maxAccel
	elif Input.is_action_pressed("ui_down"):
		accel.y = maxAccel
	else:
		accel.y = 0
	
	velocity += accel
	velocity.x = lerp(velocity.x, 0, lerpDrag)
	velocity.y = lerp(velocity.y, 0, lerpDrag)
	
	velocity.x = clamp(velocity.x, -maxSpeed, maxSpeed)
	velocity.y = clamp(velocity.y, -maxSpeed, maxSpeed)
	
	move_and_slide(velocity)

func enableShooting():
	allowShoot = true

func shoot():
	var bullet = bulletTemplate.instance()
	bullet.global_position = global_position
	bullet.rotation =  $MousePointer.global_position.angle_to_point(global_position)
	bullet.velocity = ($MousePointer.global_position - global_position).normalized() * bulletSpeed 
	allowShoot = false
	bullet.isPlayer = true
	get_parent().add_child(bullet)

func die():
	print("We are dead.")

func getHurt(damage):
	health -= damage
	$AnimationPlayer.play("Player")
