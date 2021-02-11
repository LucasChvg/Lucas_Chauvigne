using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class PlayerCC : MonoBehaviour
{
    public float WalkSpeed = 4f;
    public float SprintSpeed = 6f;
    public float JumpSpeed = 4f;
    public float sensitivity = 2.5f;
    public float Fov = 60f;
    public Vector3 MoveDirection = new Vector3(0, 0, 0);
    CharacterController player;

    public GameObject eyes;
    public GameObject Torch;

    float rotX;
    float rotY;

    float gravity = 9.81f;

    private float target_height = 1.7f;
    private float previous_y = 0.9299999f;
    private bool is_crouching = false;



    // Start is called before the first frame update
    void Start()
    {
        player = GetComponent<CharacterController>();
        Cursor.visible = false;
        rotX = 130f;
    }

    // Update is called once per frame
    void Update()
    {
        
        rotX += Input.GetAxis("Mouse X") * sensitivity * Time.timeScale;

        if(rotY < -180f)
        {
            rotY = 180f;
        }
        
        if(rotY > 180f)
        {
            rotY = -180f;
        }

        rotY -= Input.GetAxis("Mouse Y") * sensitivity * Time.timeScale;
        rotY = Mathf.Clamp(rotY, -90, 90);

        if(player.isGrounded)
        {
            MoveDirection = new Vector3(Input.GetAxis("Horizontal"), 0, Input.GetAxis("Vertical"));
            MoveDirection = transform.rotation * MoveDirection;

            if(Input.GetKey(KeyCode.LeftShift))
            {
                MoveDirection *= SprintSpeed;
            }
            else
            {
                MoveDirection *= WalkSpeed;
            }

            if(Input.GetButton("Jump"))
            {
                MoveDirection.y = JumpSpeed;
            }

            previous_y = player.transform.position.y - player.height / 2 - player.skinWidth;

            if (Input.GetKeyDown(KeyCode.LeftControl))
            {
                if(is_crouching == false)
                {
                    is_crouching = true;
                    target_height = .1f;
                }
                else
                {
                    is_crouching = false;
                    target_height = 1.7f;
                }
            }
            player.height = Mathf.Lerp(player.height, target_height, 25f * Time.deltaTime);
            player.transform.position = Vector3.Lerp(player.transform.position, new Vector3(player.transform.position.x, previous_y + target_height / 2 + player.skinWidth, player.transform.position.z), 25f * Time.deltaTime);

        }

        if(Input.GetKeyDown(KeyCode.H))
        {
            if(Torch.GetComponent<Light>().enabled == true)
            {
                Torch.GetComponent<Light>().enabled = false;
            }
            else
            {
                Torch.GetComponent<Light>().enabled =true;
            }
        }

        transform.localRotation = Quaternion.Euler(0, rotX, 0);
        eyes.transform.localRotation = Quaternion.Euler(rotY, transform.localRotation.y, 0);

        eyes.GetComponent<Camera>().fieldOfView = Fov;

        MoveDirection.y -= gravity * Time.deltaTime;
        player.Move(MoveDirection * Time.deltaTime * Time.timeScale);

    }

    public void SetSensitivity(float Sensitivity)
    {
        sensitivity = Sensitivity;
    }

    public void SetFOV(float FOV)
    {
        Fov = FOV;
    }

    public void Spawn(Vector3 pos, int x_angle, int y_angle)
    {
        player.enabled = false;
        transform.position = pos;
        player.enabled = true;
        SpawnVision(x_angle, y_angle);
    }

    public void SpawnVision(int x_angle, int y_angle)
    {
        rotX = x_angle;
        rotY = y_angle;
    }
}
