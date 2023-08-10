extends Node2D


var player = null
var allowShoot:bool = true
var shootTimer:Timer
var shootInterval = 1
var bulletTemplate = preload("res://Bullet.tscn")
var bulletSpeed = 10

# Called when the node enters the scene tree for the first time.
func _ready():
	player = get_parent().get_node("Player")
	shootTimer = Timer.new()
	shootTimer.wait_time = shootInterval
	shootTimer.autostart = true
	shootTimer.connect("timeout", self, "enableShooting")
	add_child(shootTimer)
	
	bulletSpeed = rand_range(2, 10)
	shootInterval = rand_range(.7, 1.3)

func enableShooting():
	allowShoot = true

func shoot():
	var bullet = bulletTemplate.instance()
	bullet.global_position = global_position
	bullet.rotation = player.global_position.angle_to_point(global_position)
	bullet.velocity = (player.global_position - global_position).normalized() * bulletSpeed 
	allowShoot = false
	get_parent().add_child(bullet)

# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	if player != null and allowShoot:
		shoot()
