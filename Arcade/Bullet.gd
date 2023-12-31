extends Area2D


# Declare member variables here. Examples:
# var a = 2
# var b = "text"
var velocity:Vector2 =  Vector2.ZERO
var isPlayer = false
var damage = 5
# Called when the node enters the scene tree for the first time.
func _ready():
	pass # Replace with function body.


# Called every frame. 'delta' is the elapsed time since the previous frame.
func _process(delta):
	translate(velocity)

func _on_Area2D_body_shape_entered(body_rid, body, body_shape_index, local_shape_index):
	if body is KinematicBody2D:
		if body.has_method("getHurt") and (not isPlayer and "Player" in body.name):
			body.getHurt(damage)
			queue_free()


func _on_VisibilityNotifier2D_viewport_exited(viewport):
	queue_free()
