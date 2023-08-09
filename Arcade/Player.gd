extends KinematicBody2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var velocity = Vector2.ZERO
var accel = Vector2.ZERO
var maxAccel = 50
var maxSpeed = 500
var lerpDrag = 0.2
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
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
	velocity.y = lerp(velocity.y, -maxSpeed, maxSpeed)
	
	move_and_slide(velocity)
