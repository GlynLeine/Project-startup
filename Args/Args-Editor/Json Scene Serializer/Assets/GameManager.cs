using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using System.IO;
using Newtonsoft.Json;
using Newtonsoft.Json.Converters;
using System;
using UnityEngine.SceneManagement;

public class GameManager : MonoBehaviour
{
    GameObject[] toSerialize;
    List<SerializableObject> sObjects;
    string jsonString;
    // Start is called before the first frame update
    void Start()
    {
        toSerialize = GameObject.FindGameObjectsWithTag("Serializable");
        sObjects = new List<SerializableObject>();

        for (int i = 0; i < toSerialize.Length; i++)
        {
            Debug.Log("Found Serializable");
            toSerialize[i].AddComponent<CustomScript>();
            toSerialize[i].GetComponent<CustomScript>().GetComponents();
            jsonString = "";
            CustomScript cs = toSerialize[i].GetComponent<CustomScript>();
            SerializableObject so = new SerializableObject();
            so.name = cs.gameObject.name;
            for (int j = 0; j < cs.componentList.Length; j++)
            {
                /*Adds the Transform object for serialization*/
                if (cs.componentList[j].GetType().Name.Contains("Transform"))
                {
                    Debug.Log("Added Transform");
                    SerializableTransform sTransform = new SerializableTransform();
                    sTransform.position = cs.gameObject.transform.position;
                    sTransform.rotation = cs.gameObject.transform.eulerAngles;
                    sTransform.scale = cs.gameObject.transform.localScale;

                    so.sTransform = sTransform;
                    continue;
                }

                /*Adds the MeshFilter object for serialization*/
                if (cs.componentList[j].GetType().Name.Contains("MeshFilter"))
                {
                    Debug.Log("Added MeshFilter");
                    SerializableMeshFilter sMeshFilter = new SerializableMeshFilter();
                    MeshFilter mf = cs.gameObject.GetComponent<MeshFilter>();
                    sMeshFilter.mesh = mf.mesh.name;
                    so.sMeshFilter = sMeshFilter;

                    continue;
                }

                /*Adds the MeshRenderer object for serialization*/
                if (cs.componentList[j].GetType().Name.Contains("MeshRenderer"))
                {
                    Debug.Log("Added MeshRenderer");
                    SerializableMeshRenderer sMeshRenderer = new SerializableMeshRenderer();
                    MeshRenderer mr = cs.gameObject.GetComponent<MeshRenderer>();
                    sMeshRenderer.material = mr.material.name;
                    sMeshRenderer.castShadows = mr.shadowCastingMode == UnityEngine.Rendering.ShadowCastingMode.On;
                    
                    so.sMeshRenderer = sMeshRenderer;
                    continue;
                }

                /*Adds the Rigidbody object for serialization */
                if (cs.componentList[j].GetType().Name.Contains("Rigidbody"))
                {
                    Debug.Log("Added Rigidbody");
                    SerializableRigidbody sRigidbody = new SerializableRigidbody();
                    Rigidbody rb = cs.gameObject.GetComponent<Rigidbody>();
                    sRigidbody.mass = rb.mass;
                    sRigidbody.drag = rb.drag;
                    sRigidbody.angularDrag = rb.angularDrag;
                    sRigidbody.useGravity = rb.useGravity;
                    sRigidbody.isKinematic = rb.isKinematic;
                    sRigidbody.freezeXPos = rb.constraints == RigidbodyConstraints.FreezePositionX;
                    sRigidbody.freezeYPos = rb.constraints == RigidbodyConstraints.FreezePositionY;
                    sRigidbody.freezeZPos = rb.constraints == RigidbodyConstraints.FreezePositionZ;
                    sRigidbody.freezeXRot = rb.constraints == RigidbodyConstraints.FreezeRotationX;
                    sRigidbody.freezeYRot = rb.constraints == RigidbodyConstraints.FreezeRotationY;
                    sRigidbody.freezeZRot = rb.constraints == RigidbodyConstraints.FreezeRotationZ;

                    so.sRigidbody = sRigidbody;
                    continue;
                }

                /*Adds the Collider object for serialization*/
                if (cs.componentList[j].GetType().Name.Contains("Collider"))
                {
                    Debug.Log("Added Collider");

                    if (cs.gameObject.GetComponent<BoxCollider>())
                    {
                        SerializableBoxCollider sBCollider = new SerializableBoxCollider();
                        BoxCollider bc = cs.gameObject.GetComponent<BoxCollider>();
                        sBCollider.isTrigger = bc.isTrigger;
                        sBCollider.center = bc.center;
                        sBCollider.size = bc.size;
                        so.sBCollider = sBCollider;
                        continue;
                    }
                    else if(cs.gameObject.GetComponent<SphereCollider>())
                    {
                        SerializableSphereCollider sSCollider = new SerializableSphereCollider();
                        SphereCollider sc = cs.gameObject.GetComponent<SphereCollider>();
                        sSCollider.isTrigger = sc.isTrigger;
                        sSCollider.center = sc.center;
                        sSCollider.size = sc.radius;
                        so.sSCollider = sSCollider;
                        continue;
                    }
                }

            }
            Debug.Log("Added Object");
            sObjects.Add(so);
            Debug.Log(sObjects[0].sTransform);
        }

        string finalOut = JsonConvert.SerializeObject(sObjects);
        Debug.Log(finalOut);
        System.IO.File.WriteAllText(@"C:\Users\Public\TestFolder\" + SceneManager.GetActiveScene().name + ".JSON", finalOut);
    }
}

[Serializable]
public class SerializableObject
{
    public string name;
    public SerializableTransform sTransform = null;
    public SerializableMeshFilter sMeshFilter = null;
    public SerializableMeshRenderer sMeshRenderer = null;
    public SerializableRigidbody sRigidbody = null;
    public SerializableBoxCollider sBCollider = null;
    public SerializableSphereCollider sSCollider = null;

}
[Serializable]
public class SerializableMeshFilter
{
    public string mesh;
}
[Serializable]
public class SerializableMeshRenderer
{
    public string material;
    //public string[] materials;
    public bool castShadows = true;
}
[Serializable]
public class SerializableTransform
{
    public string name = "Transform";
    public Vector3 position = Vector3.zero;
    public Vector3 rotation = Vector3.zero;
    public Vector3 scale = Vector3.one;
}
[Serializable]
public class SerializableRigidbody
{
    public float mass = 1;
    public float drag = 0;
    public float angularDrag = 0.05f;
    public bool useGravity = true;
    public bool isKinematic = false;
    public bool freezeXPos = false;
    public bool freezeYPos = false;
    public bool freezeZPos = false;
    public bool freezeXRot = false;
    public bool freezeYRot = false;
    public bool freezeZRot = false;
}
[Serializable]
public class SerializableBoxCollider
{
    public string type;
    public bool isTrigger;
    public Vector3 center = Vector3.zero;
    public Vector3 size = Vector3.one;
}
public class SerializableSphereCollider
{
    public string type;
    public bool isTrigger;
    public Vector3 center = Vector3.zero;
    public float size = 0;
}



