extends Node2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var player = null
var allowShoot:bool = true
var shootTimer:Timer
var shootInterval
var bulletTemplate = preload("res://Bullet.tscn")
# Called when the node enters the scene tree for the first time.
func _ready():
	player = get_parent().get_node("Player")
	shootTimer = Timer.new()
	shootTimer.wait_time = shootInterval
	shootTimer.autostart = true
	shootTimer.connect("timeout", self, )
	add_child(shootTimer)
	

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if player != null:
		shoot()
