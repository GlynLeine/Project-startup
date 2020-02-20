using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement : MonoBehaviour
{
    [SerializeField] float speed;

    [SerializeField] private float rotateSpeed;
    private PickUp pickUp;
    [SerializeField] private float JumpSpeed;
    private float angle;
    private float translation;
    private Vector3 Direction;
    private Vector3 deltaTurn;

    private float DistToGround;
    void Start()
    {
        pickUp = GetComponent<PickUp>();
        DistToGround = GetComponent<BoxCollider>().size.y + 0.1f;
    }

    void FixedUpdate()
    {
        //PS4 Rotation
        Direction = new Vector3(Input.GetAxis("PS4_LEFTHOR"),0,-Input.GetAxis("PS4_LEFTVERT"));
        if (Direction.sqrMagnitude > 0.01f)
        {
            Direction.Normalize();
            deltaTurn = (transform.forward + Direction * rotateSpeed * Time.deltaTime).normalized;
            transform.forward = deltaTurn;

            if (!pickUp.pickup && !pickUp.inFront)
            {
                transform.position += transform.forward * Time.deltaTime * speed;
            }
        }


        //PS4
        if (!pickUp.pickup)
        {
            if (Input.GetButtonDown("PS4_X") && CheckGrounded())
            {
                transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
            }
        }


        ////Keyboard Rotation
        //if (Input.GetKey(KeyCode.A))
        //{
        //    transform.Rotate(Vector3.up, -rotateSpeed);
        //}
        //else if(Input.GetKey(KeyCode.D))
        //{
        //    transform.Rotate(Vector3.up, rotateSpeed);
        //}

        if (!pickUp.pickup)
        {
            //if (Input.GetKeyDown(KeyCode.E) && CheckGrounded())
            //{
            //    transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
            //}
            //if (Input.GetKey(KeyCode.W) && !pickUp.inFront)
            //{
            //    transform.position += transform.forward * Time.deltaTime * speed;
            //}
            //else if (Input.GetKey(KeyCode.S))
            //{
            //    transform.position -= transform.forward * Time.deltaTime * speed;
            //}

           
        }

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
