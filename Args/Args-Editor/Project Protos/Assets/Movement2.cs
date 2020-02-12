using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement2 : MonoBehaviour
{
    [SerializeField] float speed;

    [SerializeField] private float rotateSpeed;
    private Push pushScript;
    [SerializeField] private float JumpSpeed;
    private float DistToGround;


    private float angle;
    private float translation;

    // Start is called before the first frame update
    void Start()
    {
        pushScript = GetComponent<Push>();
        DistToGround = GetComponent<BoxCollider>().size.y + 0.1f;
    }

    // Update is called once per frame
    void Update()
    {
        translation = 0;

        if (!pushScript.Pushing)
        {
            //PS4 Rotation
            angle = Input.GetAxis("Horizontal") * rotateSpeed * Time.deltaTime;
            transform.Rotate(0, angle, 0);
            if (Input.GetButtonDown("PS4_X") && CheckGrounded())
            {
                transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
            }

            //keyboard
            if (Input.GetKeyDown(KeyCode.RightShift) && CheckGrounded())
            {
                transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
            }
            if (Input.GetKey(KeyCode.LeftArrow))
            {
                transform.Rotate(Vector3.up, -rotateSpeed);
            }
            else if (Input.GetKey(KeyCode.RightArrow))
            {
                transform.Rotate(Vector3.up, rotateSpeed);
            }
        }

        //keyboard movement
        if (Input.GetKey(KeyCode.UpArrow))
        {
            transform.position += transform.forward * Time.deltaTime * speed;
        }
        else if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.position -= transform.forward * Time.deltaTime * speed;
        }


        //PS4 Movement
        
        translation = Input.GetAxis("Vertical") * speed * Time.deltaTime;
        
        if (Input.GetButtonDown("PS4_X") && CheckGrounded())
        {
            transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
        }
        transform.position += transform.forward * translation;

    }

    bool CheckGrounded()
    {
        RaycastHit hit;
        if (Physics.Raycast(transform.position, Vector3.down, out hit, DistToGround))
        {
                return true;
        }
        return false;
    }
}