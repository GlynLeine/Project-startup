using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class Movement2 : MonoBehaviour
{
    [SerializeField] float speed;

    [SerializeField] private float rotateSpeed;
    private Push pushScript;
    [SerializeField] private float JumpSpeed;
    private float angle;
    // Start is called before the first frame update
    void Start()
    {
        pushScript = GetComponent<Push>();
    }

    // Update is called once per frame
    void Update()
    {
        Debug.Log(pushScript.Pushing);
        if (!pushScript.Pushing)
        {
            if (Input.GetKeyDown(KeyCode.RightShift))
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


        if (Input.GetKey(KeyCode.UpArrow))
        {
            transform.position += transform.forward * Time.deltaTime * speed;
        }
        else if (Input.GetKey(KeyCode.DownArrow))
        {
            transform.position -= transform.forward * Time.deltaTime * speed;
        }

    }
}