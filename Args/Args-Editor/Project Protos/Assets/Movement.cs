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
    // Start is called before the first frame update
    void Start()
    {
        pickUp = GetComponent<PickUp>();
    }

    // Update is called once per frame
    void Update()
    {

        if (Input.GetKey(KeyCode.A))
        {
            transform.Rotate(Vector3.up, -rotateSpeed);
        }
        else if(Input.GetKey(KeyCode.D))
        {
            transform.Rotate(Vector3.up, rotateSpeed);
        }

        

        if (!pickUp.pickup)
        {
            if (Input.GetKeyDown(KeyCode.E))
            {
                transform.GetComponent<Rigidbody>().AddForce(Vector3.up * JumpSpeed);
            }
            if (Input.GetKey(KeyCode.W) && !pickUp.inFront)
            {
                transform.position += transform.forward * Time.deltaTime * speed;
            }
            else if (Input.GetKey(KeyCode.S))
            {
                transform.position -= transform.forward * Time.deltaTime * speed;
            }
        }


    }
}
